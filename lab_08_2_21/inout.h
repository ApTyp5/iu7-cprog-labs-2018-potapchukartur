
#ifndef __INOUT_H__
#define __INOUT_H__

#include <stdio.h>


FILE *fopen_try(char *filename, char *mod, int *rc);
double **get_mtr_2(FILE *f, int*row, int *col, int *rc);
double **alloc_matrix(int row, int col);
void put_mtr(FILE *f, double **mtr, int row, int col);

#endif

    

        








