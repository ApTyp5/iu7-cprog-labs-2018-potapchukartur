

#ifndef __DEFINE_H__
#define __DEFINE_H__

#include <stdio.h>

typedef double **matrix_t;
typedef FILE *file_t;


// Yield codes

#define     REFERENCE_ONLY          1
#define     HAPPY_END               0
#define     NON_HAPPY_END           -2
#define     FORMAT_ERROR            -3
#define     WRONG_ACTION            -4
#define     TOO_MUCH_INPUT_FILES    -5
#define     WRONG_INPUT             -6
