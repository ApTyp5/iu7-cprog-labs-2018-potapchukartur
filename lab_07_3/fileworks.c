#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fileworks.h"


FILE *fopen_try(char *filename, char *mod)
{
	FILE *f = NULL;
	f = fopen(filename, mod);
	if (!f)
		fprintf(stderr, "Can't open %s: %s\n", filename, strerror(errno));
	return f;
}


int fclose_try(FILE *f)
{
	if (fclose(f))
	{
		perror("Can't close file\n");
		return NON_HAPPY_END;
	}

	return HAPPY_END;
}

void readArr(FILE *f, int start, int end, int *mp)
{
	rewind(f);
	for (int i = 0, j; i < start; i++)
		fscanf(f, "%d", &j);
	for (int i = start; i < end; i++)
		fscanf(f, "%d", mp++);
}

void writeArr(FILE *f, int *mp, int len)
{
	for (int i = 0; i < len; i++)
		fprintf(f, "%d ", *mp++);
	fprintf(f, "\n");
}

	
	

