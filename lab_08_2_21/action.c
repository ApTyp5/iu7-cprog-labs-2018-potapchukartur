
#include <stdlib.h>
#include "aplog.h"
#include "define.h"
#include "inout.h"
#include "action.h"
#include "Ghauss.h"



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
        return Ghauss(mtr1, m1len, m1wid,
            ans, anslen, answid);
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





    
    






                




    
    




