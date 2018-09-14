#include <stdio.h>



void readArr(FILE *f, int start, int end, int *mp)
{
    fseek(f, start * sizeof(int), SEEK_SET);
    for (int i = start; i < end; i++)
        fscanf(f, "%d", mp++);
}


void writeArr(FILE *f, int *mstart, int *mend)
{
    for ( ; mstart < mend; )
        fprintf(f, "%d ", *mstart++);
    fprintf(f, "\n");
}
