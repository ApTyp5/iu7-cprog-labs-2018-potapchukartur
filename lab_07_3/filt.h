
#ifndef	__FILT_H__
#define	__FILT_H__

#include <stdio.h>
int check_int_file(FILE *const f);
int till_last_less_0(FILE *const f, int *const start, int *const end);
int common_int_filt(FILE *const f, int *const start, int *const end);
int setBorders(FILE *const f, \
		int (*filtFunc)(FILE *const, int *const, int *const),\
		int (*checkFunc)(FILE *const), int *const start,\
	        int *const end);


#endif
