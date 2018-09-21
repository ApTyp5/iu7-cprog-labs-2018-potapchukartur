#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"
#include "fileworks.h"


/*
int main()
{
    FILE *f = fopen("in", "r");

    int len = 5;

    int *pb = NULL;
    int *pe = NULL;

    frarr(f, len, &pb, &pe);

    for (int *p = pb; p < pe; p++)
        printf("%d, ", *p);

    printf("pe - pb = %ld\n", pe - pb);

    fclose(f);

    f = fopen("out", "w");

    fparr(f, pb, pe);
    
    fclose(f);


    return 0;
}

*/


    



int flen(FILE *f)
{
    rewind(f);
    int tmp;
    int len = 0;
    for (; fscanf(f, "%d", &tmp) > 0; len++)
        ;
    return len;
}


int frarr(FILE *f, int len, int **pb, int **pe, int **close_ptr)
{
    if (!len)
    {
#ifdef  NDEBUG
        fprintf(stderr, "An empty input file was given!\n");
#endif
        return EMPTY_FILE;
    }

    *pb = (int *)malloc((len+1) * sizeof(int));
    if (*pb == NULL)
    {
#ifdef  NDEBUG
        fprintf(stderr, "Allocation error!\n");
#endif  
        return ALLOCATION_ERROR;
    }


    *close_ptr = *pb;// Указатель, по которому будет освобождаться память
    *pb += 1;// Один элемент в начале осатвлен для упрощения фильтрации
    *pe = *pb;


    rewind(f);

    for (int i = 0; i < len; i++)
        fscanf(f, "%d", (*pe) + i);

    *pe += len;


    //for (; *pe - *pb < len; fscanf(f, "%d", (*pe)++))
     //   printf("%ld, ", *pe - *pb);


    return HAPPY_END;
}



void fparr(FILE *f, int *pb, int *pe)
{
    rewind(f);
    for (; pe > pb; fprintf(f, "%d ", *pb++))
            ;
    fprintf(f, "\n");
}



FILE *fopen_try(char *filename, char *mod)
{
	FILE *f = NULL;
	f = fopen(filename, mod);
#ifdef NDEBUG
	if (!f)
		fprintf(stderr, "Can't open %s: %s\n", filename, strerror(errno));
#endif
	return f;
}


int fclose_try(FILE *f)
{
	if (fclose(f))
	{
#ifdef NDEBUG
		perror("Can't close file\n");
#endif
		return FCLOSE_ERROR;
	}

	return HAPPY_END;
}


