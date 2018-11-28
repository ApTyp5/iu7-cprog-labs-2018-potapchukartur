
#ifndef __MTESTS_H__
#define __MTESTS_H__


#define STEST printf("%d --> %s(): ", __LINE__, __func__);

#define     PVERD(ftype, res, exp_res)   printf(#ftype"\t"#ftype"\t%s\n", res, exp_res, \
    res == exp_res ? "SUCCESS" : "FAIL")


// head == NULL
void add_front_test1();

// data == NULL
void add_front_test2();

// pos test
void add_front_test3();

// head == NULL
void pop_front_test1();

// *head == NULL
void pop_front_test2();

// pos test
void pop_front_test3();

#endif


