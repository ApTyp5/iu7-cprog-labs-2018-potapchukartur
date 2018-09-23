
#include <stdio.h>
#include <errno.h>

#define		HAPPY_END	    0
#define		NON_HAPPY_END	-1

#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

void fparr(FILE *f, int *pb, int *pe);
int *frarr(FILE *f, int len, int **pb, int **pe, int add);
int fint_check(FILE *f);

#endif
