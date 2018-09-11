#include "fileworks.h"
#include <stdio.h>


typedef int mytype


"./a input.txt output.txt -f"

int main(int argc, int argv)
{
	int start = 0;
	int end = 0;
	int (*filt_func)(int *start, int *end, FILE *f) = common_filt;

	int rc = format_check(argc);
	if (rc)
	{
		return FORMAT_ERROR;
	}



	FILE *f = fopen_try(argv[1], "r");
	if (!f)
	{
		return FOPEN_ERROR;
	}



	if (!rc)
	{
		if (argc == 4 && !strcmp(argv[3], "f\0"))
			filt_func = till_last_less_0;
		rc = setBorders(f, filt_func, check_int_file, &start, &end);
	}



	if (!rc)

		int *mp = malloc(sizeof(int) * (end - start));

		if (!mp)
		{
			rc = ALLOCATION_ERROR;
		}
	}



	if (!rc)
		readArr(f, start, end, mp);
	rc = fclose_try(f);

	

	if (!rc)
	{
		sortArr(start, end, mp);

		if (!(f = fopen_try(argv[2], "w")))
			rc = FOPEN_ERROR;
	}



	if (!rc)
	{
		writeArr(f, mp, end - start);
		rc = fclose_try(f);
	}



	free(mp);



	return rc

	


		









	




	







int format_check(int argc)
{
	if (argc != 3 && argc != 4)
		return FORMAT_ERROR; 
}
