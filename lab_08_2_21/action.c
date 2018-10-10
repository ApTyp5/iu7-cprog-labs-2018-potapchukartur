
#include <stdlib.h>
#include "aplog.h"
#include "define.h"
#include "inout.h"
#include "action.h"



int act(str_t action, matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
    PE;
    switch (action[0])
    {
        case 'a':
        return add(mtr1, m1len, m1wid,
            mtr2, m2len, m2wid,
            ans, anslen, answid);

        case 'm':
        return mult(mtr1, m1len, m1wid,
            mtr2, m2len, m2wid,
            ans, anslen, answid);
        case 'o':
        return 
    }

    return HAPPY_END; 
}


int add(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
    PE;
    PIV("m1len = ", m1len);
    PIV("m1wid = ", m1wid);
    PIV("m2len = ", m2len);
    PIV("m2wid = ", m2wid);
    

    if (!(m1len == m2len && m1wid == m2wid))
        return WRONG_ADD_MTR_SIZES;

    (*ans) = allocate_matrix(m1len, m1wid);
    if (!(*ans))
        return ALLOCATION_ERROR;

    *anslen = m1len;
    *answid = m1wid;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
            (*ans)[i][j] = mtr1[i][j] + mtr2[i][j];

    return HAPPY_END;
}

int mult(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
    PE;
    
    if (!(m1wid == m2len))
        return WRONG_MULT_MTR_SIZES;

    (*ans) = allocate_matrix(m1len, m2wid);

    if (!(*ans))
        return ALLOCATION_ERROR;

    *anslen = m1len;
    *answid = m2wid;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m2wid; j++)
        {
            double val = 0.0;
            for (int k = 0; k < m1wid; k++)
                val += mtr1[i][k] * mtr2[k][j];
            (*ans)[i][j] = val;
        }
    return HAPPY_END;
}


int Ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid)
{
    double *ans_col = sep_ans_col(mtr, int len, int *wid);

    if (!answer_col)
        return ALLOCATION_ERROR;

    if (len > wid)
        return NO_DESIDION;

    if (maximalize_diag(mtr, len, wid));
        return NULL_DIV;

    for (int i = 1; i < len; i++)
        for (int j = 0; j < wid; j++)
        {
            if (j < i)
                (*ans)[i][j] = 0.0;
            for (int k = j; k < wid


            str_div();
            change();
        }





    matrix_t trans = trans_mtr(mtr, len, wid);
    if (!trans)
        return ALLOCATION_ERROR;

    create_triangle_mtr(mtr, trans, len, wid);

    *anslen = len;
    *answid = 1;

    (*ans) = count_answer();
    if (!(*ans))
        return ALLOCATION_ERROR;

    free(trans);
    free(ans_col);

    return HAPPY_END;
}

matrix_t count_answer(matrix_t mtr, double *ans_col, matrix_t trans, int len, int wid)
{
    matrix_t result = allocate_matrix(len, 1);

    if (!result)
        return ALLOCATION_ERROR;

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j > 0; j++)
        {
            mtr[i][j] = 0.0;
            for (int k = i; k < len; k++)
                mtr[i][k] += 



                

}


double *sep_the_ans_col(matrix_mtr, int len, int *wid)
{
    double *result = malloc(len * sizeof(double));
    for (int i = 0; i < len; i++)
        result[i] = mtr[i][*wid - 1];
    *wid = *wid - 1;

    return result;
}


int maximalize_diag(matrix_t mtr, int len, int wid, double *ans_col)
{
    int col_elmax;

    for (int i = 0; i < len; i++)
    {
        col_elmax = maxel_num(mtr[i], i, wid);
        change_columns(mtr, len, col_elmax, i);
        change(ans_col + i, ans_col + col_elmax);

        if (abs(mtr[i][i]) < EPS)
            return NULL_DIV;
    }
    return HAPPY_END;
}




int maxel_num(double *mtr_str, int start, int wid)
{
    double tmp = mtr_str[start];
    int numeral = start;

    for (int i = start + 1, i < wid; i++)
        if (mtr_str[i] < tmp)
        {
            tmp = mtr_str[i];
            numeral = i;
        }

    return numeral;
}


void change_columns(matrix_t mtr, int len, int col1, int col2)
{
    for (int i = 0; i < len; i++)
        change(mtr[i] + col1, mtr[i] + col2);
}

void change(double *el1, double *el2)
{
    double tmp = *el1;
    *el1 = *el2;
    *el2 = tmp;
}


matrix_t trans_mtr(matrix_t mtr, int len, int wid)
{
    matrix_t result = allocate_matrix(len, wid);
    if (!result)
        return ALLOCATION_ERROR;

    zero_identify(result, len, wid);
    
    for (int i = 1; i < len; i++)
        for (int j = 0; j < i; j++)
            result[i][j] = -mtr[i][j]/mtr[i][i];

    return result;
}


create_triangle_mtr(matrix_t mtr, matrix_t trans,
    int len, int wid);
{
    for

}





    
    



}



                




    
    




