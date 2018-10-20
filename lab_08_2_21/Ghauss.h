


#ifndef __GHAUSS_H__
#define __GHAUSS_H__

#include "define.h"


int Ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid);
void str_method_max_diag(matrix_t mtr, int rate, double **ans);
void change_strs(double **aim_pv, int nmax, int j);
void change_cols(matrix_t mtr, int rate, int col1, int col2);
void change_els(double *el1, double *el2);
void add_vectors(double *vec1, double k, double *vec2, int len);
void count_ans(matrix_t ans, matrix_t mtr, int rate);
//void del_useless_cols(matrix_t mtr, int *len, int *wid);

#endif




