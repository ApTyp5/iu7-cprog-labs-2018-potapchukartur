
#include <stdio.h>




int check_int_file(FILE *f)
{
	int tmp, i;
	for (i = 0 ; fscanf(f, "%d", &tmp); i++)
		;
	if (!i)
		return EMPTY_FILE;
	if (!feof(f))
		return WRONG_INPUT;
	return HAPPY_END;
} 

int till_last_less_0(FILE *f, int *start, int *end)
{
	for (int i, j, *start = 0, *end = 0; !feof(f); j++)
	{
		if (!fscanf(f, "%d", &i))
		{
			j--;
			continue;
		}

		if (i < 0)
			*end = i;
	}	

	if (!(*end))
		*end = j;

	return HAPPY_END;
}

int common_int_filt(FILE *f, int *start, int *end)
{
	*end = 0;
	for ( ; fscanf(f, "%d", start); (*end)++)
		;
	*start = 0;

	return HAPPY_END;
}


int setBorders(FILE *f, int (*filtFunc)(FILE *, int *, int *),\
	       	int (*checkFunc)(FILE *), int *start, int *end) 
{
	if (!checkFunc(f))
	{
		return WRONG_INPUT;
	}

	if (!filtFunc(f, start, end))
	{
		return FILTER_ERROR;
	}

	return HAPPY_END;
}




	




