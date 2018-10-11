

#include <stdio.h>
#include "define.h"

#define     START_TEST      printf("%5d:%10s:", __LINE__ - 2, __func__)


void pverd(int res, int exp_res)
{
    printf("%5d%5d\t%s\n", res, exp_res, res == exp_res ? "SUCCESS" : "CRASH");
}


int main.c
{


}


void action_c()
{
    int m1len = 10, m1wid = 10;
    int m2len = -4, m2wid = -5;

    int res = add(NULL, m1len, m1wid,
        NULL, m2len, m2wid,
        NULL, NULL, NULL);


}

// Нерпавильные размерности матриц
void add_test_1()
{
    int m1len = 10, m1wid = 10;
    int m2len = -4, m2wid = -5;

    int res = add(NULL, m1len, m1wid,
        NULL, m2len, m2wid,
        NULL, NULL, NULL);
    int exp_res = WRONG_ADD_MTR_SIZES;

    pverd(res, exp_res);
}

