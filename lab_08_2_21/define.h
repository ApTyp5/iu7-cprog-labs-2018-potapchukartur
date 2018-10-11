

#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <stdio.h>

typedef double **matrix_t;
typedef double *vector_t;
typedef FILE *file_t;
typedef char *str_t;


#define     EPS     1E-5


// Yield codes

#define     REFERENCE_ONLY          1
#define     HAPPY_END               0
#define     NON_HAPPY_END           -2
#define     FORMAT_ERROR            -3
#define     WRONG_ACTION            -4
#define     TOO_MUCH_INPUT_FILES    -5
#define     WRONG_INPUT             -6
#define     ALLOCATION_ERROR        -7
#define     WRONG_ADD_MTR_SIZES     -8
#define     WRONG_MULT_MTR_SIZES    -9
#define     FOPEN_ERROR             -10
#define     NO_DESIDION             -11


#endif
