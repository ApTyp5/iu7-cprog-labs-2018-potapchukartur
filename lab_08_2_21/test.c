
#define db  printf("db\n")



#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "define.h"
#include "inout.h"
#include "action.h"

#define     START_TEST      printf("%5d:%10s:", __LINE__ - 2, __func__)

void pverd(int res, int exp_res)
{
    printf("%5d%5d\t%s\n", res, exp_res, res == exp_res ? "SUCCESS" : "CRASH");
}

matrix_t from_vector_to_matrix(double *vec, int len, int wid)
{
    matrix_t result = allocate_matrix(len, wid);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
            result[i][j] = *vec++;
    return result;
}

int mtr_cmp(double *mtr1, double *mtr2, int len, int wid)
{
    for (int i = 0; i < len + wid; i++)
            if (double_eq(*mtr1++, *mtr2++))
                return NON_HAPPY_END;
    return HAPPY_END;
}

int double_eq(double el1, double el2)
{
    if (absdiv(el1, el2) <= EPS * (el1 > el2 ? el1 : el2))
        return HAPPY_END;

    return NON_HAPPY_END;
}


double absdiv(double el1, double el2)
{
    return abs(abs(el1) - abs(el2));
}



int main()
{
    action_c();
}


void action_c()
{
    add_test_1();
    add_test_2();

}



// Нерпавильные размерности матриц
void add_test_1()
{
    START_TEST;

    int m1len = 10, m1wid = 10;
    int m2len = -4, m2wid = -5;
    int anslen, answid;


    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t mtr2 = allocate_matrix(m2len, m2wid);
    matrix_t ans;



    int res = add(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans, &anslen, &answid);
    int exp_res = WRONG_ADD_MTR_SIZES;

    pverd(res, exp_res);
}



void add_test_2()
{
    START_TEST;

    double tmp1[] = {1.1, 1.2, 1.3,
        2.1, 2.2, 2.3};
    double tmp2[] = {2.3, 2.2, 2,1,
        1.3, 1.2, 1.1};
    double tmp3[] = {3.3, 3.3, 3.3,
        3.3, 3.3, 3.3};


    int m1len = 2; 
    int m2len = 2;
    int anslen = 2;
    int m1wid = 3;
    int m2wid = 3;
    int answid = 3;

    matrix_t mtr1 = from_vector_to_matrix(tmp1, m1len, m1wid);
    matrix_t mtr2 = from_vector_to_matrix(tmp2, m2len, m2wid);
    matrix_t ans = allocate_matrix(anslen, answid);
    matrix_t exp_ans = from_vector_to_matrix(tmp3, anslen, answid);


    int res = add(mtr1, m1len, m1wid, mtr2, m2len, m2wid, &ans, &anslen, &answid);
    int exp_res = HAPPY_END;

    if (res)
        exp_res = NON_HAPPY_END;

    if (mtr_cmp((double *)ans, (double *)exp_ans, anslen, answid))
        exp_res = NON_HAPPY_END;

    pverd(res, exp_res);

}




    



