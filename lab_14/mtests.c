#include "mtests.h"
#include "mtr.h"

#ifdef mtr_el
    #undef mtr_el
    #define mtr_el int
#else
    #define mtr_el int
#endif


#define UNHAPPY_END     -10


void neg_set_test();
void pos_set_test();
void neg_get_test();
void pos_get_test();
void neg_add_test();
void pos_add_test();
void neg_mult_test();
void pos_mult_test();



int main()
{
    neg_set_test();
    pos_set_test();

    neg_get_test();
    pos_get_test();

    neg_add_test();
    pos_add_test();

    neg_mult_test();
    pos_mult_test();

    return 0;
}


void neg_set_test()
{
    STEST();

    int len = 5;
    int wid = 5;

    mtr_t *mtrcreate(len, wid);

    int out_of_range_len = 6;
    int normal_wid = 4;
    mtr_el val = 3;

    int res = mtr_set(mtr, out_of_range_len, normal_wid, val);
    int exp_res = OUT_OF_RANGE;

    PVERD(%d, res, exp_res);
}


void pos_set_test()
{
    STEST();

    int len = 6;
    int wid = 7;

    mtr_t *mtrcreate(len, wid);

    int normal_wid = 4;
    int normal_wid = 3;
    mtr_el val = 3;

    int res = mtr_set(mtr, normal_len, normal_wid, val);
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}


void neg_get_test()
{
    STEST();

    int len = 6;
    int wid = 7;

    mtr_t *mtrcreate(len, wid);

    int normal_len = 4;
    int out_of_range_wid = 10;
    mtr_el val;
 
    int res = mtr_get(mtr, normal_len, out_of_range_wid, &val);
    int exp_res = HAPPY_END;
 
    PVERD(%d, res, exp_res);
}



void pos_get_test()
{
    STEST();

    int len = 6;
    int wid = 7;

    mtr_t *mtrcreate(len, wid);

    int normal_len = 4;
    int normal_wid = 3;
    mtr_el val = 10;

    mtr_set(mtr, normal_len, normal_wid, val);
 
    int res = mtr_get(mtr, normal_len, out_of_range_wid, &val);
    res = res == val ? res : UNHAPPY_END;
    int exp_res = HAPPY_END;
 
    PVERD(%d, res, exp_res);
}



void neg_add_test()
{
    STEST();

    int len1 = 5;
    int wid1 = 5;

    int len2 = 6;
    int wid2 = 6;

    mtr_t *mtr1 = mtr_create(len1, wid1);
    mtr_t *mtr2 = mtr_create(len2, wid2);
    mtr_t *mtr3 = NULL;


    int res = mtr_add(mtr1, mtr2, &mtr3);
    int exp_res = BAD_ADD_SIZE;

    PVERD(%d, res, exp_res);
}



void pos_add_test()
{
    STEST();

    int len1 = 5;
    int wid1 = 5;

    int len2 = 6;
    int wid2 = 6;

    mtr_t *mtr1 = mtr_create(len1, wid1);
    mtr_t *mtr2 = mtr_create(len2, wid2);
    mtr_t *mtr3 = NULL;

    mtr_el val1 = 5;
    int raw1 = 1;
    int col1 = 1;

    mtr_el val2 = 4;
    int raw2 = 1;
    int col2 = 1;

    mtr_el val3 = -5;
    int raw3 = 0;
    int col3 = 0;

    mtr_set(mtr1, raw1, col1, val1);
    mtr_set(mtr2, raw2, col2, val2);
    mtr_set(mtr3, raw3, col3, val3);

    int res = mtr_add(mtr1, mtr2, &mtr3);
    int exp_res = BAD_ADD_SIZE;

    PVERD(%d, res, exp_res);
}



void neg_mult_test()
{
    STEST();

    int len1 = 3;
    int wid1 = 5;

    int len2 = 7;
    int wid2 = 6;

    mtr_t *mtr1 = mtr_create(len1, wid1);
    mtr_t *mtr2 = mtr_create(len2, wid2);
    mtr_t *mtr3 = NULL;


    int res = mtr_add(mtr1, mtr2, &mtr3);
    int exp_res = BAD_ADD_SIZE;

    PVERD(%d, res, exp_res);
}



void pos_mult_test()
{
    STEST();

    int len1 = 5;
    int wid1 = 5;

    int len2 = 4;
    int wid2 = 5;

    mtr_t *mtr1 = mtr_create(len1, wid1);
    mtr_t *mtr2 = mtr_create(len2, wid2);
    mtr_t *mtr3 = NULL;

    mtr_el val1 = 5;
    int raw1 = 1;
    int col1 = 1;

    mtr_el val2 = 4;
    int raw2 = 1;
    int col2 = 1;

    mtr_el val3 = -5;
    int raw3 = 0;
    int col3 = 0;

    mtr_set(mtr1, raw1, col1, val1);
    mtr_set(mtr2, raw2, col2, val2);
    mtr_set(mtr3, raw3, col3, val3);

    int res = mtr_add(mtr1, mtr2, &mtr3);
    int exp_res = BAD_ADD_SIZE;

    PVERD(%d, res, exp_res);
}


