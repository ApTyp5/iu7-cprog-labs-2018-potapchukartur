
#include <stdio.h>
#include <errno.h>

#define		HAPPY_END	    0
#define		NON_HAPPY_END	-1

#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

FILE *fopen_try(char *filename, char *mod);
int fclose_try(FILE *f);
void fparr(FILE *f, int *pb, int *pe);
int frarr(FILE *f, int len, int **pb, int **pe, int **);
int flen(FILE *f);

#endif
