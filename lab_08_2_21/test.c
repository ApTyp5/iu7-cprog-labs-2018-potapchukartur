
#include <stdlib.h>
#include <stdio.h>
#include "Ghauss.h"
#include "prompt.h"
#include "action.h"
#include "inout.h"
#include "define.h"
#include "test.h"
#include "mtests.h"



int main()
{
    //    tprompt();

    tformat_check_1();//app.exe 1 2 (ac = 3)
    tformat_check_2();//app.exe incorrect (ac = 4, av[1] = "qux")
    tformat_check_3();//app.exe o in1 in2 out (ac = 5, av[1] = "o"
    tformat_check_4();//app.exe o in1 out(pos)
    tformat_check_5();//app.exe a in1 in2 out(pos)
    tformet_check_6();//app.exe m in1 in2 out(pos)
    tformat_check_7();//app.exe h(pos)


//    taction();

    tadd_1();//pos
    tadd_2();//neg

    tmult_1();//pos
    tmult_2();//neg

/*
    tact_1();//add pos
    tact_2();//add neg
    tact_3();//mult pos
    tact_4();//mult neg
    tact_5();//Ghauss pos
    tact_6();//Ghauss neg
    */


//    tGhauss();

    tadd_vectors();

    tcount_ans();

    tchange_els();

    tchange_cols();

    tchange_strs();

    tGhauss_1();//pos
    tGhauss_2();//neg
//    tGhauss_3();//alloc_err

    tstr_method_max_diag();


    

//    tinout();


    return 0;
}


double dfloat_max(double el1, double el2)
{
    return (el1 > el2) ? el1 : el2;
}

int dfloat_cmp(double el1, double el2)
{
    return abs(abs(el1) - abs(el2)) < abs(EPS * dfloat_max(el1, el2))\
        ? HAPPY_END : NON_HAPPY_END;
}




void tadd_1()
{
    STEST;

    int m1len = 2, m1wid = 2;
    int m2len = 2, m2wid = 2;
    int m3len = 2, m3wid = 2;
    int anslen, answid;

    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t mtr2 = allocate_matrix(m2len, m2wid);
    matrix_t mtr3 = allocate_matrix(m3len, m3wid);
    matrix_t ans_mtr;

    mtr1[0][0] = 0.0;
    mtr1[0][1] = 0.1;
    mtr1[1][0] = 1.0;
    mtr1[1][1] = 1.1;

    mtr2[0][0] = 0.0;
    mtr2[0][1] = 0.1;
    mtr2[1][0] = 1.0;
    mtr2[1][1] = 1.1;

    mtr3[0][0] = 0.0;
    mtr3[0][1] = 0.2;
    mtr3[1][0] = 2.0;
    mtr3[1][1] = 2.2;

    int res = add(mtr1, 2, 2, mtr2, 2, 2,
        &ans_mtr, &anslen, &answid);

    int exp_res = HAPPY_END;

    if (!res)
    {
        for (int i = 0; i < anslen; i++)
            for (int j = 0; j < answid; j++)
                if (ans_mtr[i][j] != mtr3[i][j])
                {
                    res = i * anslen + j;
                    break;
                }
    }
    else
        printf("Note! The add return val is not HAPPY_END\n");

    PVERD(%d, res, exp_res);
}

void tadd_2()
{
    STEST;

    int m1len = 2, m1wid = 5;
    int m2len = 7, m2wid = 2;
    int anslen, answid;

    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t mtr2 = allocate_matrix(m2len, m2wid);
    matrix_t ans_mtr;
    
    int res = add(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans_mtr, &anslen, &answid);
    int exp_res = WRONG_ADD_MTR_SIZES;

    PVERD(%d, res, exp_res);
}




void tmult_1()
{
    STEST;

    int m1len = 2, m1wid = 3;
    int m2len = 3, m2wid = 2;
    int m3len = 2, m3wid = 2;
    int anslen, answid;

    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t mtr2 = allocate_matrix(m2len, m2wid);
    matrix_t mtr3 = allocate_matrix(m3len, m3wid);
    matrix_t ans_mtr;

    mtr1[0][0] = 1.0;
    mtr1[0][1] = 1.1;
    mtr1[1][0] = 1.2;
    mtr1[1][1] = 1.3;

    mtr2[0][0] = 2.0;
    mtr2[0][1] = 2.1;
    mtr2[1][0] = 2.2;
    mtr2[1][1] = 2.3;

    mtr3[0][0] = 7.3;
    mtr3[0][1] = 7.63;
    mtr3[1][0] = 9.28;
    mtr3[1][1] = 9.7;

    int res = mult(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans_mtr, &anslen, &answid);
    int exp_res = HAPPY_END;

    if (!res)
    {
        for (int i = 0; i < anslen; i++)
            for (int j = 0; j < answid; j++)
                if (ans_mtr[i][j] != mtr3[i][j])
                {
                    res = i * anslen + j;
                    break;
                }
    }
    else
        printf("[Note! The mult return val is not HAPPY_END]\n");

    PVERD(%d, res, exp_res);
}
   
    

void tmult_2()
{
    STEST;

    int m1len = 2, m1wid = 2;
    int m2len = 2, m2wid = 2;
    int anslen, answid;

    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t mtr2 = allocate_matrix(m2len, m2wid);
    matrix_t ans_mtr;
    
    int res = mult(mtr1, m1len, m1wid,
        mtr2, m2len, m2wid,
        &ans_mtr, &anslen, &answid);
    int exp_res = WRONG_MULT_MTR_SIZES;

    PVERD(%d, res, exp_res);
}


void tGhauss_1()
{
    STEST;

    int mlen = 2, mwid = 3;
    int alen, awid;

    matrix_t mtr = allocate_matrix(mlen, mwid);
    matrix_t mtr3 = allocate_matrix(mwid - 1, 1);
    matrix_t ans;

    mtr[0][0] = 2.2;
    mtr[0][1] = -3.3;
    mtr[0][2] = 12.4;
    mtr[1][0] = 7.33;
    mtr[1][1] = 1.3;
    mtr[1][2] = 14.2;

    mtr3[0][0] = 2.33; 
    mtr3[1][0] = -2.21;

    int res = Ghauss(mtr, mlen, mwid,
        &ans, &alen, &awid);
    int exp_res = HAPPY_END;

    if (!res)
    {
        for (int i = 0; i < alen; i++)
            for (int j = 0; j < awid; j++)
                if (ans[i][j] != mtr3[i][j])
                {
                    res = i * alen + j;
                    break;
                }
    }
    else
        printf("[Note! The Ghauss return val is not HAPPY_END]\n");

    PVERD(%d, res, exp_res);
}


void tGhauss_2()
{
    STEST;

    int m1len = 2, m1wid = 9;
    int anslen, answid;

    matrix_t mtr1 = allocate_matrix(m1len, m1wid);
    matrix_t ans_mtr;
    
    int res = Ghauss(mtr1, m1len, m1wid,
        &ans_mtr, &anslen, &answid);
    int exp_res = WRONG_SLAU_MTR_SIZES;

    PVERD(%d, res, exp_res);
}



void tstr_method_max_diag()
{
    STEST;

    int rate = 2;

    matrix_t mtr = allocate_matrix(rate, rate);
    matrix_t aim_pv = allocate_matrix(rate, 1);

    mtr[0][0] = 0.0;
    mtr[0][1] = 1.0;
    mtr[1][0] = 1.0;
    mtr[1][1] = 1.1;

    aim_pv[0][0] = 1.0;
    aim_pv[1][0] = 2.0;

    str_method_max_diag(mtr, rate, aim_pv);

    int res = HAPPY_END;
    int exp_res = HAPPY_END;

    if (mtr[0][0] * mtr[1][1] == 0.0)
        exp_res = 1;
    else if (aim_pv[0][0] == 1.0 || aim_pv[1][0] == 2.0)
        exp_res = 2;

    PVERD(%d, res, exp_res);
}


void tchange_strs()
{
    STEST;

    int rate = 2;

    matrix_t aim_pv = allocate_matrix(rate, 1);

    aim_pv[0][0] = 1.0;
    aim_pv[1][0] = 2.0;

    change_strs(aim_pv, 0, 1);

    int exp_res = HAPPY_END;
    int res = aim_pv[0][1] == 1.0 ? HAPPY_END : 1;

    if (!res && aim_pv[0][0] == 2.0)
        res = 2;

    PVERD(%d, res, exp_res);
}


void tchange_cols()
{
    STEST;

    int rate = 2;
    int col1 = 0, col2 = 1;

    matrix_t mtr = allocate_matrix(rate, rate);

    mtr[0][col1] = 0.0;
    mtr[0][col2] = 0.1;

    int exp_res = HAPPY_END;
    int res = HAPPY_END;

    change_cols(mtr, rate, col1, col2);

    if (mtr[0][col1] == 0.0 || mtr[0][col2] == 0.1)
        res = NON_HAPPY_END;

    PVERD(%d, res, exp_res);
}


void tchange_els()
{
    STEST;

    double a = 5.0, b = 10.0;

    change_els(&a, &b);

    int res = (b == 5.0 && a == 10.0) ? HAPPY_END : NON_HAPPY_END;
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}

    

void tadd_vectors()
{
    STEST;

    int len = 3;

    double vec1[len], vec2[len];
    double k = 2.0;

    vec1[0] = 1.0;
    vec1[1] = 1.1;
    vec1[2] = 1.2;

    vec2[0] = 2.0;
    vec2[1] = 2.1;
    vec2[2] = 2.2;

    add_vectors(vec1, k, vec2, len);

    int exp_res = HAPPY_END;
    int res = HAPPY_END;

    if (vec2[0] != 4.0)
        res = 1;
    else if (vec2[1] != 4.3)
        res = 2;
    else if (vec2[2] != 4.6)
        res = 3;

    PVERD(%d, res, exp_res);
}



void tcount_ans()
{
    STEST;

    int rate = 2;

    matrix_t mtr = allocate_matrix(rate, rate + 1);
    matrix_t ans = allocate_matrix(rate, 1);
    matrix_t exp_ans = allocate_matrix(rate, 1);

    mtr[0][0] = 2.2;
    mtr[0][1] = -3.3;
    mtr[0][2] = 12.4;
    mtr[1][0] = 0.0;
    mtr[1][1] = 12.295;
    mtr[1][2] = -27.11;

    exp_ans[0][0] = 2.33;
    exp_ans[1][0] = -2.21;

    count_ans(ans, mtr, rate);

    int exp_res = HAPPY_END;
    int res = HAPPY_END;

    for (int i = 0; i < rate; i++)
            if (!dfloat_cmp(exp_ans[i][0], ans[i][0]))
            {
                res = i + 1;
                break;
            }

    PVERD(%d, res, exp_res);
}
                        


//app.exe 1 2 (ac = 3)
void tformat_check_1()
{
    STEST;

    int ac = 3;
    char *av[] = {"app.exe", "m", "in"};
    
    int res = format_check(ac, av);
    int exp_res = FORMAT_ERROR;
   
    PVERD(%d, res, exp_res);
}



//app.exe incorrect (ac = 4, av[1] = "qux")
void tformat_check_2()
{
    STEST;

    int ac = 4;
    char *av[] = {"app.exe", "UNEXISING", "in", "out"};
    
    int res = format_check(ac, av);
    int exp_res = WRONG_ACTION;
   
    PVERD(%d, res, exp_res);
}



//app.exe o in1 in2 out (ac = 5, av[1] = "o"
void tformat_check_3()
{
    STEST;

    int ac = 5;
    char *av[] = {"app.exe", "o", "in1", "in2", "out"};
    
    int res = format_check(ac, av);
    int exp_res = TOO_MUCH_INPUT_FILES;
   
    PVERD(%d, res, exp_res);
}

//app.exe o in1 out(pos)
void tformat_check_4()
{
    STEST;

    int ac = 4;
    char *av[] = {"app.exe", "o", "in", "out"};
    
    int res = format_check(ac, av);
    int exp_res = HAPPY_END;
   
    PVERD(%d, res, exp_res);
}

//app.exe a in1 in2 out(pos)
void tformat_check_5()
{
    STEST;

    int ac = 5;
    char *av[] = {"app.exe", "a", "in1", "in2", "out"};
    
    int res = format_check(ac, av);
    int exp_res = HAPPY_END;
   
    PVERD(%d, res, exp_res);
}

//app.exe m in1 in2 out(pos)
void tformet_check_6()
{
    STEST;

    int ac = 5;
    char *av[] = {"app.exe", "m", "in1", "in2", "out"};
    
    int res = format_check(ac, av);
    int exp_res = HAPPY_END;
  
    PVERD(%d, res, exp_res);
}


//app.exe h(pos)
void tformat_check_7()
{
    STEST;

    int ac = 2;
    char *av[] = {"app.exe ", "h"};

    int res = format_check(ac, av);
    int exp_res = REFERENCE_ONLY;

    PVERD(%d, res, exp_res);
}
