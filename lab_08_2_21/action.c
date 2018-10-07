
#include "inout.h"


int add(double **mtr_1, int mtr1_len, int mtr1_wid,
    double **mtr_2, int mtr2_len, int mtr2_wid,
    double **ans, int ans_len, int ans_wid)
{
    if (mtr1_len == mtr2_len &&
        mtr1_wid == mtr2_wid)
    {
        ans = alloc_matrix(mtr1_len, mtr2_len);
        ans_len = mtr1_len;
        ans_wid = mtr1_wid;
    }
    else
        return WRONG_ADD_SIZES;

    if (!ans)
        return ALLOCATION_ERROR;
    
    for (int i = 0; i < ans_len; i++)
        for (int j = 0; j < ans_wid; j++)
        ans[i][j] = mtr1[i][j] + mtr2[i][j];

    return HAPPY_END;
}




int mult(double **mtr_1, int mtr1_len, int mtr1_wid,
    double **mtr_2, int mtr2_len, int mtr2_wid,
    double **ans, int ans_len, int ans_wid)
{
    if (mtr1_len == mtr2_wid)
    {
        ans = alloc_matrix(mtr1_len, mtr2_wid);
        ans_len = mtr1_len;
        ans_wid = mtr2_wid;
    }
    else
        return WRONG_MULT_SIZES;

    if (!ans)
        return ALLOCATION_ERROR;

    for (int i = 0; i < ans_len; i++)
        for (int j = 0; j < ans_wid; j++)
            ans[i][j] = 0.0;


    for (int i = 0; i < ans_len; i++)
        for (int j = 0; j < ans_wid; j++)
            for (int k = 0; k < ans_len; k++)
                ans[i][j] += mtr1[i][k] * mtr2[k][j];

    return HAPPY_END;
}



int action(char *act,
    double **mtr_1, int mtr1_len, int mtr1_wid,
    double **mtr_2, int mtr2_len, int mtr2_wid, 
    double **answer, int ans_len, int ans_wid)
{
    switch(act[0])
    {
        case('a'):

        case('m'):

        case('o'):
    }
}
    

