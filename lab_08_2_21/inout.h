

#ifndef __INOUT_H__
#define __INOUT_H__

#include "define.h"

int fopen_try(file_t *f, str_t fname, str_t mod);
int read_mtr(str_t fname, matrix_t *mtr, int *len, int *wid,
    int get_mtr(file_t, matrix_t *, int *len, int *wid));

int get_mtr_m2(file_t f, matrix_t *mtr, int *len, int *wid);
matrix_t allocate_matrix(int len, int wid);
void zero_identify(matrix_t *mtr, int len, int wid);
int write_mtr(str_t fname, matrix_t mtr, int len, int wid,
    void put_mtr(file_t, matrix_t, int len, int wid));

void put_mtr_m1(file_t f, matrix_t mtr, int len, int wid);

#endif





   
