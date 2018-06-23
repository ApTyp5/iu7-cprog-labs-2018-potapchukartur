#define 	HAPPY_END	0
#define 	NON_HAPPY_END	-2

#include <stdio.h>


int in(char c, char *arr, int n)
{

	for (int i = 0; i < n; i++)
		if (c ==  *(arr + i))
			return HAPPY_END;

	return NON_HAPPY_END;
}



int sum(int *a, int n)
{
	int summ = 0;
	for (int i = 0; i < n; i++)
		summ += *(a + i);

	return summ;
}


int format_check(int a)
{
	if (a == 3)
		return HAPPY_END;
 
	fprintf(stderr, "Format of the function: a <input file> <output file>\n");
}
