
#ifndef __TEST_H__
#define __TEST_H__

#include "define.h"

void pverd(int res, int exp_res);
matrix_t from_vector_to_matrix(double *vec, int len, int wid);
int mtr_cmp(double *mtr1, double *mtr2, int len, int wid);
int double_eq(double el1, double el2);
double absdiv(double el1, double el2);



void action_c();
void add_test_1();
void add_test_2();

#endif



    



