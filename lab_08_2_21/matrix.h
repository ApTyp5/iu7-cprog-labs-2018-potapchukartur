
#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef double **matrix_t;


matrix_t get_mtr(char *fnam, int *mlen, int *mwid, int *rc);
int put_mtr(matrix_t mtr, int len, int wid, char *fnam);
matrix_t alloc_mtr(int len, int wid);
FILE *fopen_try(char *fnam, char *mod, int *rc);
int mtr_add(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid);
int mtr_mult(matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid);
int mtr_trans(matrix_t *mtr, int *len, int *wid);
int mtr_ghauss(matrix_t mtr, int len, int wid,
    matrix_t *ans, int *anslen, int *answid);
void max_diag(matrix_t mtr, int mlen, int xnum,
    matrix_t ans);
void change_raws(matrix_t mtr, int raw1, int raw2);
void change_cols(matrix_t mtr, int len, int col1, int col2);
void change_doubls(double *el1, double *el2);
void triange_matrix(matrix_t mtr, int rate);
void count_answer(matrix_t mtr, int rate, matrix_t ans);

#endif






