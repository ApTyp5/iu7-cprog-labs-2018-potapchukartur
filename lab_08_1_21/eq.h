
#ifndef __EQ_H__
#define __EQ_H__

#include "matrix.h"

int epseq(double el1, double el2);
int mtr_eq(matrix_t mtr1, int m1len, int m1wid,
           matrix_t mtr2, int m2len, int m2wid);
int mtr_epseq(matrix_t mtr1, int m1len, int m1wid,
              matrix_t mtr2, int m2len, int m2wid);

#endif


