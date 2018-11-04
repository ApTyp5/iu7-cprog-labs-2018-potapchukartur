#include <math.h>
#include "debug.h"
#include <assert.h>
#include <stdlib.h>
#include "define.h"
#include "matrix.h"



matrix_t get_mtr(char *fnam, int *mlen, int *mwid, int *rc)
{
    matrix_t mtr = NULL;
    int nonull_el;
    int raw, col;
    double val;

    FILE *f = fopen_try(fnam, "r", rc);

    if (!(*rc) && 
        (fscanf(f, "%d%d%d", mlen, mwid, &nonull_el) != 3 ||
         *mlen <= 0 || *mwid <= 0 || nonull_el <= 0 ||
         nonull_el > (*mlen) * (*mwid)))
        *rc = WRONG_INPUT;
    

    if (!(*rc) && (mtr = alloc_mtr(*mlen, *mwid)) == NULL)
        *rc = ALLOC_ERROR;

    if (!(*rc))
        for (int i = 0; i < nonull_el; i++)
        {
            if (fscanf(f, "%d%d%lf", &raw, &col, &val) != 3 ||
                0 >= raw || raw > *mlen || 
                0 >= col || col > *mwid)
            {
                *rc = WRONG_INPUT;
                break;
            }
            mtr[raw - 1][col - 1] = val;
        }

    if (!(*rc) && fscanf(f, "%d%d%lf", &raw, &col, &val) == 3)
        *rc = WRONG_INPUT;

    if (f)
        fclose(f);

    return mtr;
}

matrix_t get_classic_mtr(char *fnam, int *mlen, int *mwid, int *rc)
{
    matrix_t mtr = NULL;
    FILE *f = fopen_try(fnam, "r", rc);

    if (!(*rc) && (fscanf(f, "%d%d", mlen, mwid) != 2))
        *rc = WRONG_INPUT;
    if (!(*rc) && (mtr = alloc_mtr(*mlen, *mwid)) == NULL)
        *rc = ALLOC_ERROR;

    if (!(*rc))
    {
        for (int raw = 0; raw < *mlen; raw++)
            for (int col = 0; col < *mwid; col++)
                if (fscanf(f, "%lf", mtr[raw] + col) == UNHAPPY_END)
                   *rc = WRONG_INPUT;
    }

    return mtr;
} 
    






matrix_t alloc_mtr(int len, int wid)
{

   matrix_t result = malloc(len * sizeof(double *) + len * wid * sizeof(double));

    if (!result)
       return NULL;

    for (int i = 0; i < len; i++)
        result[i] = (double *)((char *)result + len * sizeof(double *) + i * wid * sizeof(double));

    for (int i = 0; i < len; i++)
        for(int j = 0; j < wid; j++)
            result[i][j] = 0.0;

    return result;
}



FILE *fopen_try(char *fnam, char *mod, int *rc)
{
    FILE *f = fopen(fnam, mod);
    if (!f)
        *rc = FOPEN_ERROR;
    return f;
}

int put_mtr(matrix_t mtr, int len, int wid, char *fnam)
{
    int rc = HAPPY_END;
    FILE *f = fopen_try(fnam, "w", &rc);

    fprintf(f, "%d %d\n", len, wid);

    if (!rc)
        for (int i = 0; i < len; i++)
            for (int j = 0; j < wid; j++)
                fprintf(f, "%lf%s", mtr[i][j], (j + 1) % wid ? " " : "\n");

    if (f)
        rc = fclose(f);

    return rc;
}


int mtr_add(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
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
    return HAPPY_END;
}

int mtr_mult(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
    if (m1wid != m2len)
        return WRONG_MULT_SIZES;

    if (!((*ans) = alloc_mtr(m1len, m2wid)))
        return ALLOC_ERROR;

    *anslen = m1len;
    *answid = m2wid;

    if (mtr_trans(&mtr2, &m2len, &m2wid) != HAPPY_END)
        return ALLOC_ERROR;

    // В дальнейшем в качестве размерностей будем 
    // иcпользовать m1len, m2len и m2wid, чтобы обращаться
    // к размерностям не через разыменование
    

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m2len; j++)
            for (int k = 0; k < m2wid; k++)
                (*ans)[i][j] += mtr1[i][k] * mtr2[j][k];

    return HAPPY_END;
}


int mtr_trans(matrix_t *mtr, int *len, int *wid)
{
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
    return HAPPY_END;
}

  

int mtr_ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid)
{
    ps(mtr:\n);
    pmat(%lf\40, mtr, len, wid);
    // xmum - кол-во неизвестных
    int xnum = wid - 1;
    if (len != xnum)
        return WRONG_GHAUSS_SIZES;

    *anslen = xnum;
    *answid = 1;

    *ans = alloc_mtr(xnum, 1);
    if (!(*ans))
        return ALLOC_ERROR;

    max_diag(mtr, len, *ans);

    //if (check_diag(mtr, len) == UNHAPPY_END)
    //    return WRONG_INPUT;
    ps(mtr:\n);
    pmat(%lf\40, mtr, len, wid);

    triange_matrix(mtr, xnum);
    count_answer(mtr, xnum, *ans);

    return HAPPY_END;
}

int check_diag(matrix_t mtr, int rate)
{
    for (int i = 0; i < rate; i++)
        if (mtr[i][i] == 0.0)
            return UNHAPPY_END;

    return HAPPY_END;
} 

// Переставляет столбцы матрицы так, чтобы
// на главной диагонали находились максимально
// возможные элементы
void max_diag(matrix_t mtr, int rate,
    matrix_t ans)
{
    double maxel;
    int maxcol;

    // Вместо 'raw < rate - 1' можно напсать 'raw < rate'.
    // Так будет логичнее, но итог будет одинаковый, так 
    // как цикл после при 'raw = rate - 1' не выполнится
    // ни разу
    for (int raw = 0; raw < rate - 1; raw++)
    {
        // Иницилизируем максимльный элемент элементом на главной диагонали
        maxel = mtr[raw][raw];
        maxcol = raw;
        for (int col = raw + 1; col < rate; col++)
            if (fabs(mtr[raw][col]) > fabs(maxel))
            {
                maxcol = col;
                maxel = mtr[raw][col];
            }
        if (maxcol != raw)
        {
            change_cols(mtr, rate, raw, maxcol);
            change_raws(ans, raw, maxcol);
        }
    }
}

void change_raws(matrix_t mtr, int raw1, int raw2)
{

    double *tmp = mtr[raw1];
    mtr[raw1] = mtr[raw2];
    mtr[raw2] = tmp;
}

void change_cols(matrix_t mtr, int len, int col1, int col2)
{
    for (int i = 0; i < len; i++)
    {
        change_doubls(mtr[i] + col1, mtr[i] + col2);
    }
}

void change_doubls(double *el1, double *el2)
{
    double tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}

void triange_matrix(matrix_t mtr, int rate)
{
    // xnum + 1 - это ширина исходной матрицы
    // Далее:
    // diag - диагональ матрицы
    // raw - строка, в которой выполняются преобразования
    for (int diag = rate - 1; diag > -1; diag--)
    {
        for (int raw = diag - 1; raw > -1; raw--)
        {
            int col;
            int k = mtr[raw][diag]/mtr[diag][diag];

            mtr[raw][rate] -= k * mtr[diag][rate];

            for (col = rate - 1; col >= diag; col--)
                mtr[raw][col] = 0.0;

            for (; col > - 1; col--)
                mtr[raw][col] -= k * mtr[diag][col];
        }
    }
}

void count_answer(matrix_t mtr, int rate, matrix_t ans)
{
    for (int i = 0; i < rate; i++)
    {
        ans[i][0] = mtr[i][rate];// mtr[i][rate] - элемент столбца свободных членов
        for (int j = i - 1; j > -1; j--)
            ans[i][0] -= mtr[i][j] * ans[j][0];

        ans[i][0] /= mtr[i][i];
    }
}



