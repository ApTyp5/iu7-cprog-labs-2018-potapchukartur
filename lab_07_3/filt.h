
#ifndef	__FILT_H__
#define	__FILT_H__

#include <stdio.h>

int check_int_file(FILE *f);
int till_last_less_0(FILE *f, int *start, int *end);
int common_int_filt(FILE *f, int *start, int *end);
int setBorders(FILE *f, int (*filtFunc)(FILE *, int *, int *), \
		int (*checkFunc)(FILE *), int *start, int *end);

#endif
