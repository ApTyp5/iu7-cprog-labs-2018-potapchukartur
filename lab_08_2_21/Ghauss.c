
#include <stdlib.h>
#include "define.h"
#include "Ghauss.h"
#include "inout.h"
#include "aplog.h"




int Ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid)
{
    PE;
    PIV("len = ", len);
    PIV("wid = ", wid);
    PMAT("init mtr:\n", mtr, len, wid, " ");

    int num_of_x = wid - 1; 

    if (len != num_of_x)
        return WRONG_SLAU_MTR_SIZES;

    *anslen = num_of_x;
    *answid = 1;

    (*ans) = allocate_matrix(num_of_x, 1);

    if (!(*ans))
        return ALLOCATION_ERROR;
    zero_identify(ans, num_of_x, 1);

    //del_useless_cols(mtr, &len, &wid);

    col_method_max_diag(mtr, wid, *ans);

    for (int j = 0; j < wid - 1; j++)
        for (int i = j + 1; i < len; i++)
            add_vectors(mtr[j] + j, -mtr[i][j]/mtr[j][j], mtr[i] + j, len - j + 1); // +1 добавляем, т к хотим изменять и столбец свободных членов 

    count_ans(*ans, mtr, wid);

    return HAPPY_END;
}

/*
// Обрезание матрицы до квадратной, причем в столбце mtr[wid]
// останутся свободные члены
void del_useless_cols(matrix_t mtr, int *len, int *wid)
{
    for (int i = 0; i < *len; i++)
        mtr[i][*len] = mtr[i][*wid - 1]; // Помещаем столбец свободных членов в len + 1-ый столбец ( в будующем wid + 1)

    *wid = *len;
}

*/


void col_method_max_diag(matrix_t mtr, int rate, double **ans)
{
    PE;
    PIV("rate = ", rate);
    PMAT("rated mtr:\n", mtr, rate, rate, " ");
    PMAT("rated ans:\n", ans, rate, 1, " ");


    double maxel;
    int nmax;

    for (int j = 0; j < rate; j++)
    {
        maxel = mtr[0][j];
        nmax = 0;
        for (int i = 1; i < rate; i++)
            if (mtr[i][j] > maxel)
            {
                maxel = mtr[i][j];
                nmax = i;
            }
        if (nmax != j)
        {
            change_cols(mtr, rate, nmax, j);
            change_ptrs(ans, nmax, j);
        }
    }
}

void change_ptrs(double **aim_pv, int nmax, int j)
{
    PE;
    PM("no output\n");

    double *tmp = aim_pv[j];
    aim_pv[j] = aim_pv[nmax];
    aim_pv[nmax] = tmp;
}

void change_cols(matrix_t mtr, int rate, int col1, int col2)
{
    PE;
    PIV("rate = ", rate);
    PIV("num of col 1 = ", col1);
    PIV("num of col 2 = ", col2);
    PMAT("rated mtr:\n", mtr, rate, rate, " ");


    for (int i = 0; i < rate; i++)
        change_els(mtr[i] + col1, mtr[i] + col2);
}

void change_els(double *el1, double *el2)
{
    PE;
    PFV("el1 = ", *el1);
    PFV("el2 = ", *el2);

    double tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}



// add vec1 * k to vec2 
void add_vectors(double *vec1, double k, double *vec2, int len)
{
    PE;
    PFV("k = ", k);
    PIV("len = ", len);
    PMAS("vec1 : ", vec1, len, " ");
    PMAS("vec2 : ", vec2, len, " ");


    for (int i = 0; i < len; i++)
        *vec2++ += k * (*vec1++);
}


// Считает ответ квадратной СЛАУ
void count_ans(matrix_t ans, matrix_t mtr, int rate)
{
    PE;
    PIV("rate = ", rate);
    PMAT("rated_ans :\n", ans, rate, rate, " ");
    PMAT("rated_mtr + free col :\n", mtr, rate, (rate + 1), " ");



    for (int i = rate - 1; i > -1; i--)
    {
        // mtr[i][rate] - свободный член i-ой строки
        ans[i][0] = mtr[i][rate];
        for (int j = i + 1; j < rate; j++)
            ans[i][0] -= ans[j][0] * mtr[i][j];

        ans[i][0] /= mtr[i][i];
    }
}





