#include <stdio.h>

#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

int safety_frarr(char *fnam, int **close_ptr, int **begin, int **end);
int safety_fparr(char *fnam, int *begin, int *end);

FILE *fopen_try(const char *const filename, const char *const mod, int *rc);
void fparr(FILE *f, const int *pb, const int *pe);
int *frarr(FILE *f, int len, int **pb, int **pe, int add, int *rc);
int fint_check(FILE *f);
int file_check(FILE *f, int *len);

#endif
