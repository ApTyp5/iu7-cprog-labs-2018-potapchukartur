
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

// head == NULL
void front_back_split_test1();

// back == NULL
void front_back_split_test2();

// pos test
void front_back_split_test3();

// neitral test
void remove_duplicates_test1();
// neg test
void remove_duplicates_test2();
// pos test
void remove_duplicates_test3();

//neg test
void list_front_reversed_extend_test1();
// *head == NULL
void list_front_reversed_extend_test2();
// pos test
void list_front_reversed_extend_test3();

// pos test
void sorted_merge_test1();


#endif


