#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "fileworks.h"


/*
int main()
{

    FILE *f = tmpfile();

    fprintf(f, " 5 ");

    printf("%d\n", fint_check(f));
    fclose(f);


    return 0;
}
*/




    



int fint_check(FILE *f)
{
    rewind(f);
    int read = 0;
    int len = 0;
    int sig = 1;


    for (; (sig = fscanf(f, "%d", &read)) > 0; len++);
    if (sig)
        return len;

    return WRONG_INPUT;
}


int *frarr(FILE *f, int len, int **pb, int **pe, int add)
{
    *pb = (int *)malloc((len + add) * sizeof(int));
    if (*pb == NULL)
        return NULL;


    *pb += add;// Доп. элементы для доп. информации
    *pe = *pb;


    rewind(f);

    for (int i = 0; i < len; i++)
        fscanf(f, "%d", (*pe)++);


    //for (; *pe - *pb < len; fscanf(f, "%d", (*pe)++))
     //   printf("%ld, ", *pe - *pb);


    return *pb - add;
}



void fparr(FILE *f, int *pb, int *pe)
{
    rewind(f);
    for (; pe > pb; fprintf(f, "%d ", *pb++));
    fprintf(f, "\n");
}



