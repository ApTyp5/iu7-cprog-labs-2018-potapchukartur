#include <stdio.h>



void readArr(FILE * f, const int start, const int end, int *mp)
{
    fseek(f, start * sizeof(int), SEEK_SET);
    for (int i = start; i < end; i++)
        fscanf(f, "%d", mp++);
}


void writeArr(FILE *const f, int *mstart, const int *const mend)
{
    for ( ; mstart < mend; )
        fprintf(f, "%d ", *mstart++);
    fprintf(f, "\n");
}
