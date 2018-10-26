
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "aplog.h"
#include "define.h"

#define db  printf("db\n")


matrix_t lazy_get_mtr(char *fnam, int *len, int *wid)
{
    FILE *f = fopen(fnam, "r");
    if (!f)
        return NULL;
    
    if (fscanf(f, "%d%d", len, wid) != 2)
        return NULL;

    matrix_t result = alloc_mtr(*len, *wid);
    if (!result)
    {
        fprintf(stderr, "Alloc error!");
        return NULL;
    }

    for (int i = 0; i < *len; i++)
        for (int j = 0; j < *wid; j++)
            fscanf(f, "%lf", result[i] + j);

    return result;
}

double double_abs_max(double el1, double el2)
{
    double tmp1 = abs(el1);
    double tmp2 = abs(el2);

    return tmp1 > tmp2 ? tmp1 : tmp2;
}

int double_eq(double el1, double el2)
{
    return abs(abs(el1) - abs(el2)) < double_abs_max(el1, el2) * EPS;
}

int mtr_eq(matrix_t mtr1, int m1len, int m1wid,
     matrix_t mtr2, int m2len, int m2wid)
{
    if (m1len != m2len || m1wid != m2wid)
        return BAD_END;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
            if (!double_eq(mtr1[i][j], mtr2[i][j]))
                return BAD_END;
    return HAPPY_END;
}




int main()
{
    S_LOG;

    int reclen, recwid;
    int anslen, answid;

    system("./app.exe a ./tests/in_11 ./tests/in_12 out");

    matrix_t rec = lazy_get_mtr("out", &reclen, &recwid);
    matrix_t ans = lazy_get_mtr("./tests/out_1", &anslen, &answid);

    printf("Test 1 passet : %s\n", !mtr_eq(rec, reclen, recwid, ans, anslen, answid) ? "SUCCESS" : "FAIL");

    E_LOG;

    return 0;
}

    

