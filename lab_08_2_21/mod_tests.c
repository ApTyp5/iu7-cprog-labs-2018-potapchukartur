#include <stdlib.h>
#include "tests.h"
#include "mtests.h"
#include "define.h"
#include "matrix.h"
#include "debug.h"
#include "math.h"


int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    phat();

    tst_epseq1();
    tst_epseq2();

    tst_mtr_eq1();//WRONG_SIZES
    tst_mtr_eq2();//NON EQ MTRS
    tst_mtr_eq3();//EQ MTRS

    tst_mtr_epseq1();//WRONG_SIZES
    tst_mtr_epseq2();//NON EPSEQ MTRS
    tst_mtr_epseq3();//EPSEQ MTRS

    tst_fopen_try1();//FOPEN_ERROR
    tst_fopen_try2();//HAPPY_END
    
    tst_get_mtr1();//WRONG_INPUT
    tst_get_mtr2();//WRONG_INPUT#2
    tst_get_mtr3();//HAPPY_END
    
    tst_put_mtr1();//FOPEN_ERROR
    tst_put_mtr2();//HAPPY_END

    tst_mtr_add1();//WRONG_ADD_SIZES
    tst_mtr_add2();//HAPPY_END

    tst_mtr_mult1();//WRONG_MULT_SIZES
    tst_mtr_mult2();//HAPPY_END


    tst_mtr_trans();//HAPPY_END
    tst_change_doubls();//HAPPY_END
    tst_change_cols();//HAPPY_END
    tst_change_raws();//HAPPR_END
    tst_max_diag();//HAPPY_END
//    tst_triange_matrix();//HAPPY_END
//   tst_count_answer();//HAPPY_END

//    tst_mtr_ghauss();//WRONG_GHAUSS_SIZES
//    tst_mtr_ghauss();//HAPPY_END
    
    return 0;
}

/////ADD ONES/////

void phat()
{
    printf("line\trecieved\texpected\tverdict\n");
}

int epseq(double el1, double el2)
{
    double ael1 = fabs(el1);
    double ael2 = fabs(el2);
    double maxel = ael1 >= ael2 ? ael1 : ael2;
    if (maxel == 0.0)
        return HAPPY_END;
    
    if (fabs(ael1 - ael2) < EPS * maxel)
        return HAPPY_END;

    return BAD_END;
}

int mtr_eq(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid)
{
    if (m1len != m2len || m1wid != m2wid)
        return BAD_END;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
            if (mtr1[i][j] != mtr2[i][j])
                return BAD_END;
    return HAPPY_END;
}

int mtr_epseq(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid)
{
    /*
    piv(m1len);
    piv(m1wid);
    piv(m2len);
    piv(m2wid);
    */

    if (m1len != m2len || m1wid != m2wid)
        return BAD_END;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
        {
//            piv(i); piv(j); pdv(mtr1[i][j]); pdv(mtr2[i][j]);

            if (epseq(mtr1[i][j], mtr2[i][j]) == BAD_END)
                return BAD_END;
        }

    return HAPPY_END;
}

////////TESTS//////////
void tst_epseq1()//EPSEQ DOUBLES
{
    STEST;
    double el1 = 1.11;
    double el2 = 1.1;

    int res = epseq(el1, el2);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}

void tst_epseq2()//NONEPSEQ DOUBLES
{
    STEST;

    double el1 = 10.0;
    double el2 = 9.0;

    int res = epseq(el1, el2);
    int exp_res = BAD_END;

    PVERD(res, exp_res);
}

void tst_mtr_eq1()//WRONG_SIZES
{
    STEST;
    int m1len = 5, m1wid = 4;
    int m2len = 3, m2wid = 2;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    int res = mtr_eq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = BAD_END;

    PVERD(res, exp_res);
}


void tst_mtr_eq2()//NONEQ MTRS
{
    STEST;
    int m1len = 5, m1wid = 4;
    int m2len = 5, m2wid = 4;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    mtr1[1][1] = 1.2;
    mtr2[1][1] = 1.1;

    int res = mtr_eq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = BAD_END;

    PVERD(res, exp_res);
}

void tst_mtr_eq3()//EQ MTRS
{
    STEST;
    int m1len = 5, m1wid = 4;
    int m2len = 5, m2wid = 4;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    mtr1[1][1] = 1.1;
    mtr2[1][1] = 1.1;

    int res = mtr_eq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}



void tst_mtr_epseq1()//WRONG_SIZES
{
    STEST;
    int m1len = 5, m1wid = 4;
    int m2len = 3, m2wid = 2;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    int res = mtr_epseq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = BAD_END;

    PVERD(res, exp_res);
}


void tst_mtr_epseq2()//NONEQ MTRS
{
    STEST;

    int m1len = 5, m1wid = 4;
    int m2len = 5, m2wid = 4;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    mtr1[1][1] = 1.3;
    mtr2[1][1] = 1.0;


    int res = mtr_epseq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = BAD_END;

    PVERD(res, exp_res);
}

void tst_mtr_epseq3()//EQ MTRS
{
    STEST;
    int m1len = 5, m1wid = 4;
    int m2len = 5, m2wid = 4;

    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    mtr1[1][1] = 1.1;
    mtr2[1][1] = 1.11;

    int res = mtr_epseq(mtr1, m1len, m1wid, mtr2, m2len, m2wid);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}

void tst_fopen_try1()//FOPEN_ERROR
{
    STEST;

    int res = HAPPY_END;

    fopen_try("unex", "r", &res);

    int exp_res = FOPEN_ERROR;

    PVERD(res, exp_res);
}

void tst_fopen_try2()//HAPPY_END
{
    STEST;

    int res = HAPPY_END;
    FILE *f = fopen_try("ex.test", "w", &res);

    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
    fclose(f);
    system("rm ex.test");
}

void tst_get_mtr1()//WRONG_INPUT
{
    STEST;

    int res = HAPPY_END;
    int exp_res = FOPEN_ERROR;

    int len, wid;
    len = wid;

    get_mtr("unex", &len, &wid, &res);

    PVERD(res, exp_res);
}

void tst_get_mtr2()//WRONG_INPUT#2
{
    STEST;

    int res = HAPPY_END;
    int exp_res = WRONG_INPUT;

    int len, wid;

    FILE *f = fopen("ex.test", "w");
    fprintf(f, "qwer");
    fclose(f);

    get_mtr("ex.test", &len, &wid, &res);

    PVERD(res, exp_res);

    system("rm ex.test");
}



void tst_get_mtr3()//HAPPY_END
{
    STEST;

    int res = HAPPY_END;

    FILE *f = fopen("ex.test", "w");
    fprintf(f, "2 3 3\n"
        "1 1 1.1\n"
        "2 2 -2.2\n"
        "2 3 -2.3\n");
    fclose(f);

    int len, wid;
    matrix_t mtr = get_mtr("ex.test", &len, &wid, &res);

    int exp_len = 2;
    int exp_wid = 3;
    matrix_t exp_mtr = alloc_mtr(exp_len, exp_wid);
    exp_mtr[0][0] = 1.1;
    exp_mtr[1][1] = -2.2;
    exp_mtr[1][2] = -2.3;

    res = mtr_epseq(mtr, len, wid, exp_mtr, exp_len, exp_wid);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
    system("rm ex.test");
}

void tst_put_mtr1()//FOPEN_ERROR
{
    STEST;
    int len = 3, wid = 3;
    matrix_t mtr = alloc_mtr(len, wid);
    mtr[1][1] = 1.1;
    mtr[2][2] = -2.2;

    FILE *f = fopen("ex.test", "w");

    int res = put_mtr(mtr, len, wid, "ex.test");
    int exp_res = FOPEN_ERROR;
    fclose(f);


    PVERD(res, exp_res);
    system("rm ex.test");
}

void tst_put_mtr2()//HAPPY_END
{
    STEST;
    int len = 3, wid = 3;
    matrix_t mtr = alloc_mtr(len, wid);
    mtr[1][1] = 1.1;
    mtr[2][2] = -2.2;

    int res = put_mtr(mtr, len, wid, "ex.test");
    int exp_res = HAPPY_END; 

    PVERD(res, exp_res);
}

void tst_mtr_add1()//WRONG_ADD_SIZES
{
    STEST;
    int m1len = 3, m1wid = 4;
    matrix_t mtr1 = alloc_mtr(m1len, m1wid);

    int m2len = 4, m2wid = 3;
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    int anslen, answid;
    matrix_t ans;

    int res = mtr_add(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans, &anslen, &answid);
    int exp_res = WRONG_ADD_SIZES;

    PVERD(res, exp_res);
}

void tst_mtr_add2()//HAPPY_END
{
    STEST;

    int m1len = 4, m1wid = 3;
    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    mtr1[0][0] = 15.3;
    mtr1[3][2] = 3.2;
    mtr1[0][2] = -0.2;

    int m2len = 4, m2wid = 3;
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);
    mtr2[0][0] = 10.2;
    mtr2[3][2] = -3.2;
    mtr2[3][0] = -0.3;

    int exp_len = 4, exp_wid = 3;
    matrix_t exp_ans = alloc_mtr(exp_len, exp_wid);
    exp_ans[0][0] = 25.5;
    exp_ans[3][2] = 0.0;
    exp_ans[0][2] = -0.2;
    exp_ans[3][0] = -0.3;


    int anslen, answid;
    matrix_t ans;

    int res = mtr_add(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans, &anslen, &answid);

    if (res == HAPPY_END)
        res = mtr_epseq(ans, anslen, answid, 
            exp_ans, exp_len, exp_wid);

    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}


void tst_mtr_mult1()//WRONG_MULT_SIZES
{
    STEST;

    int m1len = 4, m1wid = 3;
    matrix_t mtr1 = alloc_mtr(m1len, m1wid);

    int m2len = 4, m2wid = 3;
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);

    int anslen, answid;
    matrix_t ans;


    int res = mtr_mult(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans, &anslen, &answid);

    int exp_res = WRONG_MULT_SIZES;

    PVERD(res, exp_res);
}

void tst_mtr_mult2()//HAPPY_END
{
    STEST;

    int m1len = 2, m1wid = 3;
    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    mtr1[0][0] = 1.0;
    mtr1[0][1] = 1.1;
    mtr1[0][2] = -1.2;
    mtr1[1][0] = 2.0;
    mtr1[1][1] = 2.1;
    mtr1[1][2] = -2.2;

    int m2len = 3, m2wid = 2;
    matrix_t mtr2 = alloc_mtr(m2len, m2wid);
    mtr2[0][0] = 2.0;
    mtr2[0][1] = -2.1;
    mtr2[1][0] = 3.0;
    mtr2[1][1] = -3.1;
    mtr2[2][0] = 4.0;
    mtr2[2][1] = -4.1;


    int exp_len = 2, exp_wid = 2;
    matrix_t exp_ans = alloc_mtr(exp_len, exp_wid);
    exp_ans[0][0] = 0.5;
    exp_ans[0][1] = -0.59;
    exp_ans[1][0] = 1.5;
    exp_ans[1][1] = -1.69;


    int anslen, answid;
    matrix_t ans;

    int res = mtr_mult(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans, &anslen, &answid);

    if (res == HAPPY_END)
        res = mtr_epseq(ans, anslen, answid, 
            exp_ans, exp_len, exp_wid);

    int exp_res = HAPPY_END;


    PVERD(res, exp_res);
}

void tst_mtr_trans()//HAPPY_END
{
    STEST;

    int m1len = 2, m1wid = 3;
    matrix_t mtr1 = alloc_mtr(m1len, m1wid);
    mtr1[0][0] = 1.0;
    mtr1[0][1] = 1.1;
    mtr1[0][2] = -1.2;
    mtr1[1][0] = 2.0;
    mtr1[1][1] = 2.1;
    mtr1[1][2] = -2.2;

    int exp_len = 3, exp_wid = 2;
    matrix_t exp_mtr = alloc_mtr(exp_len, exp_wid);
    exp_mtr[0][0] = 1.0;
    exp_mtr[0][1] = 2.0;
    exp_mtr[1][0] = 1.1;
    exp_mtr[1][1] = 2.1;
    exp_mtr[2][0] = -1.2;
    exp_mtr[2][1] = -2.2;

    int res = mtr_trans(&mtr1, &m1len, &m1wid);

    if (!res)
        res = mtr_eq(mtr1, m1len, m1wid,
        exp_mtr, exp_len, exp_wid);

    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}

void tst_change_doubls()//HAPPY_END
{
    STEST;
    double d1 = 5.5;
    double d2 = -254.398;

    change_doubls(&d1, &d2);

    int exp_res = HAPPY_END;
    int res = (d2 == 5.5 && d1 == -254.398) ? HAPPY_END : BAD_END;

    PVERD(res, exp_res);
}


void tst_change_cols()//HAPPY_END
{
    STEST;
    int len = 2, wid = 2;
    matrix_t mtr = alloc_mtr(len, wid);
    mtr[0][0] = 0.0;
    mtr[0][1] = 0.1;
    mtr[1][0] = 1.0;
    mtr[1][1] = 1.1;

    change_cols(mtr, len, 0, 1);

    matrix_t ans = alloc_mtr(len, wid);
    ans[0][0] = 0.1;
    ans[0][1] = 0.0;
    ans[1][0] = 1.1;
    ans[1][1] = 1.0;

    int res = mtr_eq(mtr, len, wid, ans, len, wid);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}


void tst_change_raws()//HAPPY_END
{
    STEST;

    int len = 2, wid = 2;
    matrix_t mtr = alloc_mtr(len, wid);
    mtr[0][0] = 0.0;
    mtr[0][1] = 0.1;
    mtr[1][0] = 1.0;
    mtr[1][1] = 1.1;

    change_raws(mtr, 0, 1);

    matrix_t ans = alloc_mtr(len, wid);
    ans[0][0] = 1.0;
    ans[0][1] = 1.1;
    ans[1][0] = 0.0;
    ans[1][1] = 0.1;

    int res = mtr_eq(mtr, len, wid, ans, len, wid);
    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}

void tst_max_diag()//HAPPY_END
{
    STEST;

    int rate = 5;
    matrix_t mtr = alloc_mtr(rate, rate);
    matrix_t help = alloc_mtr(rate, 1);

    for (int i = 0; i < rate; i++)
        help[i][0] = i;

    // Заполняем поледний столбец матрицы тройками.
    // Так как остальная часть заполнена нулями, то
    // в итоге тройки должны оказаться на гл. диагонали
    mtr[0][3] = 1.0;
    mtr[1][4] = 2.0;
    mtr[2][0] = 3.0;
    mtr[3][1] = 4.0;
    mtr[4][2] = 5.0;

    max_diag(mtr, rate, help);

    int res = (mtr[0][0] == 1.0 && 
        mtr[1][1] == 2.0 &&
        mtr[2][2] == 3.0 &&
        mtr[3][3] == 4.0 &&
        mtr[4][4] == 5.0) ? HAPPY_END : BAD_END;

    int exp_res = HAPPY_END;

    PVERD(res, exp_res);
}





















