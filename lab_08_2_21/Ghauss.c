
#include <stdlib.h>
#include "define.h"
#include "Ghauss.h"
#include "inout.h"




int Ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid)
{
    int num_of_x = wid - 1; 

    if (len != num_of_x)
        return WRONG_SLAU_MTR_SIZES;
    *anslen = num_of_x;
    *answid = 1;

    (*ans) = allocate_matrix(num_of_x, 1);
    if (!(*ans))
        return ALLOCATION_ERROR;

    zero_identify(ans, num_of_x, 1);
    str_method_max_diag(mtr, num_of_x, *ans);



    for (int j = 0; j < wid - 1; j++)
        for (int i = j + 1; i < len; i++)
            add_vectors(mtr[j] + j, -mtr[i][j]/mtr[j][j], mtr[i] + j, len - j + 1); // +1 добавляем, т к хотим изменять и столбец свободных членов 

    count_ans(*ans, mtr, num_of_x);

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


void str_method_max_diag(matrix_t mtr, int rate, double **ans)
{
    double maxel;
    int nmax;

    for (int i = 0; i < rate; i++)
    {
        maxel = mtr[i][i];
        nmax = i;
        for (int j = i + 1; j < rate; j++)
            if (mtr[i][j] > maxel)
            {
                maxel = mtr[i][j];
                nmax = j;
            }
        if (nmax != i)
        {
            change_cols(mtr, rate, nmax, i);
            change_strs(ans, nmax, i);
        }


    }
}

// По факту эта ф-я применяется для замены указателей
void change_strs(double **mtr, int i, int j)
{
    double *tmp = mtr[j];
    mtr[j] = mtr[i];
    mtr[i] = tmp;
}

void change_cols(matrix_t mtr, int rate, int col1, int col2)
{
    for (int i = 0; i < rate; i++)
        change_els(mtr[i] + col1, mtr[i] + col2);
}

void change_els(double *el1, double *el2)
{
    double tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}



// add vec1 * k to vec2 
void add_vectors(double *vec1, double k, double *vec2, int len)
{
    for (int i = 0; i < len; i++)
        *vec2++ += k * (*vec1++);
}


// Считает ответ квадратной СЛАУ
void count_ans(matrix_t ans, matrix_t mtr, int rate)
{
    for (int i = rate - 1; i > -1; i--)
    {
        // mtr[i][rate] - свободный член i-ой строки
        ans[i][0] = mtr[i][rate];
        for (int j = i + 1; j < rate; j++)
            ans[i][0] -= ans[j][0] * mtr[i][j];

        ans[i][0] /= mtr[i][i];
    }
}





