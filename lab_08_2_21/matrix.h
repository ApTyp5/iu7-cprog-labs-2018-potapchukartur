
#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef double **matrix_t;


matrix_t get_mtr(char *fnam, int *mlen, int *mwid, int *rc);
matrix_t alloc_mtr(int len, int wid);
FILE *fopen_try(char *fnam, char *mod, int *rc);
int put_mtr(matrix_t mtr, int len, int wid, char *fnam);
int mtr_add(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid);
int mtr_mult(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid);
int mtr_trans(matrix_t *mtr, int *len, int *wid);
int mtr_ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid);

#endif






