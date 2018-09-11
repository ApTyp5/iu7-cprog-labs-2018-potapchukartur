#include <stdio.h>



int numInFile(FILE *f)
{
	int result = 0, i;

	for (; fscanf("%d", &i); result++)
		;

	return result;
}



