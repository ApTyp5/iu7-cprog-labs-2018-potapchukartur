#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "filt.h"
#include "inout.h"
#include "sort.h"
#include "fileworks.h"

void *malloc_try(size_t);
int format_check(int);



int main(int argc, char **argv)
{
	int start = 0;
	int end = 0;
	int (*filt_func)(FILE *f, int *start, int *end) = common_int_filt;
	int *mp = NULL;




	int rc = format_check(argc); 
	if (rc)
		return FORMAT_ERROR;



	FILE *f = fopen_try(argv[1], "r");
	if (!f)
		return FOPEN_ERROR;



	if (!rc)
	{
		if (argc == 4 && !strcmp(argv[3], "f\0"))
			filt_func = till_last_less_0;
		rc = setBorders(f, filt_func, check_int_file, &start, &end);
	}



	if (!rc)
	{
		mp = malloc_try(sizeof(int) * (end - start));
		if (!mp)
			rc = ALLOCATION_ERROR;

		int *emp = mp + (end - start);
	}



	if (!rc)
	{
		readArr(f, start, end, mp);
		if (fclose_try(f))
			rc = FCLOSE_ERROR;
	}
	else
		fclose(f);



	if (!rc)
	{
		sortArr(start, end, mp);

		if (!(f = fopen_try(argv[2], "w")))
			rc = FOPEN_ERROR;
	}



	if (!rc)
	{
		writeArr(f, mp, emp);
		rc = fclose_try(f);
	}



	if (mp)
		free(mp);



	return rc
}



void *malloc_try(size_t size)
{
	void result = malloc(size);
	if (!result)
		fprintf(stderr, "Allocation error!\n");

	return result;
}
		


int format_check(int argc)
{
	if (argc != 3 && argc != 4)
		fprintf(stderr, "Format error!\n");
		return FORMAT_ERROR; 
}
