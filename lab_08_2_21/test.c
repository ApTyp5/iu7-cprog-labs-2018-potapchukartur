#include <stdio.h>
#include "inout.h"
#include "define.h"
#include "test.h"

#define HAPPY_END   0
#define         COMMON_VARS    int line = __LINE__ -2;\
                                    int rc = HAPPY_END;\
                                    int result;\
                                    int exp_res







int main()
{
    inout();
    
    return HAPPY_END;
}


char *verd(int result, int exp_res)
{
    return result == exp_res ? "SUCCESS" : "CRACH";
}

void pverd(int line, char *name, int result, int exp_res) 
{
    printf("%d <-- %s:\t%s\n", line, name, verd(result, exp_res));
}  


void inout()
{
    fopen_try_test_1();
    fopen_try_test_2();
    get_mtr_test_1();
    get_mtr_test_2();
    get_mtr_test_3();
    get_mtr_test_4();
    get_mtr_test_5();
}


void fopen_try_test_1()
{
    COMMON_VARS;

    FILE *f = fopen_try("anyFile.txt", "w", &rc);
    f = (void *)f;


    result = rc;
    exp_res = HAPPY_END;

    pverd(line, "fopen_try_test_1", result, exp_res);
}

void fopen_try_test_2()
{
    COMMON_VARS;

    FILE *f = fopen_try("unexisting.txt", "r", &rc);
    f = (void *)f;


    result = rc;
    exp_res = FOPEN_ERROR;

    pverd(line, "fopen_try_test_2", result, exp_res);
}

void get_mtr_test_1()
{
    COMMON_VARS;
    int row, col;

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "qwer asdf zxcv");
    rewind(f);

    double **dres = get_mtr_2(f, &row, &col, &rc);
    dres = (void *)dres;


    result = rc;
    exp_res = WRONG_INPUT;

    pverd(line, "germtr_test_1", result, exp_res);
}

void get_mtr_test_2()
{
    COMMON_VARS;
    int row, col;

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "3 3 3\n");
    fprintf(f, "qwer asdf");

    double **dres = get_mtr_2(f, &row, &col, &rc);
    dres = (void *)dres;

    result = rc;
    exp_res = WRONG_INPUT;

    pverd(line, "germtr_test_2", result, exp_res);
}


void get_mtr_test_3()
{
    COMMON_VARS;
    int row, col;

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "5 6 3\n");
    fprintf(f, "1 1 1.1\n");
    fprintf(f, "10 3 1.1\n");

    double **dres = get_mtr_2(f, &row, &col, &rc);
    dres = (void *)dres;

    result = rc;
    exp_res = WRONG_INPUT;

    pverd(line, "germtr_test_3", result, exp_res);
}


void get_mtr_test_4()
{
    COMMON_VARS;
    int row, col;

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "5 6 3\n");
    fprintf(f, "1 1 1.1\n");
    fprintf(f, "1 10 1.1\n");

    double **dres = get_mtr_2(f, &row, &col, &rc);

    dres = (void *)dres;

    result = rc;
    exp_res = WRONG_INPUT;

    pverd(line, "germtr_test_4", result, exp_res);
}



void get_mtr_test_5()
{
    COMMON_VARS;
    int row, col;

    FILE *f = fopen("test.txt", "w");
    fprintf(f, "5 6 3\n");
    fprintf(f, "1 1 1.1\n");
    fprintf(f, "1 5 1.5\n");
    fprintf(f, "4 3 4.3\n");

    rewind(f);

    double **dres = get_mtr_2(f, &row, &col, &rc);
    dres = (void *)dres;

    result = rc;
    exp_res = HAPPY_END;

    if ( dres[0][0] != 1.1 || dres[0][4] != 1.5 ||
        dres[3][2] != 4.3 || dres[1][0] != 0.0 || 
        dres[4][5] != 0.0)
        result = NON_HAPPY_END;

    pverd(line, "germtr_test_4", result, exp_res);
}




    










