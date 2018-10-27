
#include <assert.h>
#include <stdlib.h>
#include "define.h"
#include "aplog.h"
#include "matrix.h"

#define db  printf("db\n")


matrix_t get_mtr(char *fnam, int *mlen, int *mwid, int *rc)
{
#ifdef  JOURNAL
    LOG_IN;
#endif

    int nonull_el;
    matrix_t mtr = NULL;
    int raw, col;
    double val;


    FILE *f = fopen_try(fnam, "r", rc);

    if (!*rc && fscanf(f, "%d%d%d", mlen, mwid, &nonull_el) != 3)
        *rc = WRONG_INPUT;

    if (!*rc && (mtr = alloc_mtr(*mlen, *mwid)) == NULL)
        *rc = ALLOC_ERROR;

    if (!*rc)
        for (int i = 0; i < nonull_el; i++)
        {
            if (fscanf(f, "%d%d%lf", &raw, &col, &val) != 3 ||
                raw > *mlen || col > *mwid)
            {
                *rc = WRONG_INPUT;
                break;
            }

            mtr[raw - 1][col - 1] = val;
        }

    if (f)
        fclose(f);

#ifdef  JOURNAL
    LOG_OUT;
#endif
    return mtr;
}





matrix_t alloc_mtr(int len, int wid)
{
#ifdef  JOURNAL
    LOG_IN;
#endif


   matrix_t result = malloc(len * sizeof(double *) + len * wid * sizeof(double));

    if (!result)
       return NULL;

    for (int i = 0; i < len; i++)
        result[i] = (double *)((char *)result + len * sizeof(double *) + i * wid * sizeof(double));

    for (int i = 0; i < len; i++)
        for(int j = 0; j < wid; j++)
            result[i][j] = 0.0;

#ifdef  JOURNAL
    LOG_OUT;
#endif

    return result;
}



FILE *fopen_try(char *fnam, char *mod, int *rc)
{
#ifdef  JOURNAL
    LOG_IN;
    PV(opening file %20s\n, fnam);
#endif


    FILE *f = fopen(fnam, mod);
    if (!f)
        *rc = FOPEN_ERROR;
#ifdef  JOURNAL
    PV(rc after opening file = %d\n, *rc);
    LOG_OUT;
#endif
    return f;
}

int put_mtr(matrix_t mtr, int len, int wid, char *fnam)
{
#ifdef  JOURNAL
    LOG_IN;
    PV(len of out mtr = %d\n, len);
    PV(wid of out mtr = %d\n, wid);
#endif
    int rc = HAPPY_END;
    FILE *f = fopen_try(fnam, "w", &rc);

    fprintf(f, "%d %d\n", len, wid);

    if (!rc)
        for (int i = 0; i < len; i++)
            for (int j = 0; j < wid; j++)
                fprintf(f, "%lf%s", mtr[i][j], (j + 1) % wid ? " " : "\n");

    if (f)
        rc = fclose(f);

#ifdef  JOURNAL
    LOG_OUT;
#endif
    return rc;
}


int mtr_add(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
#ifdef  JOURNAL
    LOG_IN; 
#endif

    if (m1len != m2len || m1wid != m2wid)
        return WRONG_ADD_SIZES;

    *anslen = m1len;
    *answid = m1wid;
    *ans = alloc_mtr(m1len, m1wid);
    if (!(*ans))
        return ALLOC_ERROR;

    // В дальнейшем в качестве размерностей будем 
    // сипользовать m1len и m1wid, чтобы обращаться
    // к размерностям не через разыменование
 

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
            (*ans)[i][j] = mtr1[i][j] + mtr2[i][j];
#ifdef  JOURNAL
    LOG_OUT;
#endif
    return HAPPY_END;
}

int mtr_mult(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
#ifdef  JOURNAL
    LOG_IN; 
    PS(Before trans\n);
    PM(%lf\40, mtr2, m2len, m2wid);
#endif

    if (m1wid != m2len)
        return WRONG_MULT_SIZES;

    *anslen = m1len;
    *answid = m2wid;
    *ans = alloc_mtr(m1len, m2wid);
    if (!(*ans))
        return ALLOC_ERROR;

    if (mtr_trans(&mtr2, &m2len, &m2wid) != HAPPY_END)
        return ALLOC_ERROR;

    // В дальнейшем в качестве размерностей будем 
    // сипользовать m1len, m2len и m2wid, чтобы обращаться
    // к размерностям не через разыменование
    

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m2len; j++)
            for (int k = 0; k < m2wid; k++)
                (*ans)[i][j] += mtr1[i][k] * mtr2[j][k];
#ifdef  JOURNAL
    LOG_OUT;
    PS(After trans);
    PM(%lf\40, mtr2, m2len, m2wid);
#endif
    return HAPPY_END;
}


int mtr_trans(matrix_t *mtr, int *len, int *wid)
{
#ifdef  JOURNAL
    LOG_IN;
#endif

    matrix_t result = alloc_mtr(*wid, *len);
    if (!result)
        return ALLOC_ERROR;

    for (int i = 0; i < *wid; i++)
        for (int j = 0; j < *len; j++)
            result[i][j] = (*mtr)[j][i];

    int tmp = *len;
    *len = *wid;
    *wid = tmp;

    free(*mtr);
    *mtr = result;
#ifdef  JOURNAL
    LOG_OUT;
#endif
    return HAPPY_END;
}

  

int mtr_ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid)
{
#ifdef  JOURNAL
    LOG_IN; 
#endif
    // xmum - кол-во неизвестных
    int xnum = wid - 1;
    if (len != xnum)
        return WRONG_GHAUSS_SIZES;

    *anslen = xnum;
    *answid = 1;

    *ans = alloc_mtr(xnum, 1);
    if (!(*ans))
        return ALLOC_ERROR;

#ifdef JOURNAL
    PS(mtr before max_diag\n);
    PM(%lf\40, mtr, len, wid);
#endif
    max_diag(mtr, len, *ans);


#ifdef JOURNAL
    PS(mtr before triangle_matrix\n);
    PM(%lf\40, mtr, len, wid);
#endif

    triange_matrix(mtr, xnum);



#ifdef JOURNAL
    PS(mtr before count_answer\n);
    PM(%lf\40, mtr, len, wid);
#endif
   count_answer(mtr, xnum, *ans);


#ifdef  JOURNAL
    LOG_OUT; 
#endif
    return HAPPY_END;
}



void max_diag(matrix_t mtr, int rate,
    matrix_t ans)
{
#ifdef  JOURNAL
    LOG_IN;
#endif
    int maxel, maxcol;

    for (int i = 0; i < rate; i++)
    {
        maxel = mtr[i][i];
        maxcol = i;
        for (int j = i + 1; j < rate; j++)
            if (mtr[i][j] > maxel)
            {
                maxcol = j;
                maxel = mtr[i][j];
            }
        if (maxcol != i)
        {
            change_cols(mtr, rate, i, maxcol);
            change_raws(ans, i, maxcol);
        }
    }
#ifdef  JOURNAL
    LOG_OUT;
#endif
}

void change_raws(matrix_t mtr, int raw1, int raw2)
{
#ifdef  JOURNAL
    LOG_IN;
#endif

    double *tmp = mtr[raw1];
    mtr[raw1] = mtr[raw2];
    mtr[raw2] = tmp;
#ifdef  JOURNAL
    LOG_OUT;
#endif
}


void change_cols(matrix_t mtr, int len, int col1, int col2)
{
#ifdef  JOURNAL
    LOG_IN;
#endif
    for (int i = 0; i < len; i++)
        change_doubls(mtr[len] + col1, mtr[len] + col2);
#ifdef  JOURNAL
    LOG_OUT;
#endif
}


void change_doubls(double *el1, double *el2)
{
#ifdef  JOURNAL
    LOG_IN;
#endif
    double tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
#ifdef  JOURNAL
    LOG_OUT;
#endif
}


void triange_matrix(matrix_t mtr, int rate)
{
#ifdef  JOURNAL
    LOG_IN;
#endif
    // xnum + 1 - это ширина исходной матрицы
    
    // Далее:
    // diag - диагональ матрицы
    // raw - строка, в которой выполняются преобразования
    for (int diag = 0; diag < rate; diag++)
    {
        for (int raw = diag + 1; raw < rate; raw++)
        {
            int col;
            int k = mtr[raw][diag]/mtr[diag][diag];

            for (col = 0; col < diag; col++)
                mtr[raw][col] = 0.0;

            for (; col <= rate; col++)
                mtr[raw][col] -= k * mtr[diag][col];
        }
    }
#ifdef  JOURNAL
    LOG_OUT;
#endif
}


void count_answer(matrix_t mtr, int rate, matrix_t ans)
{
#ifdef  JOURNAL
    LOG_IN;
#endif
    for (int i = rate - 1; i > -1; i--)
    {
        ans[i][0] = mtr[i][rate];// mtr[i][rate] - элемент столбца свободных членов
        for (int j = rate - 1; j > i; j--)
            ans[i][0] -= mtr[i][j] * ans[j][0];
        ans[i][0] /= mtr[i][i];
    }
#ifdef  JOURNAL
    LOG_OUT;
#endif
}


