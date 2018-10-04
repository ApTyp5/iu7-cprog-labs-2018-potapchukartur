#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "define.h"
#include "inout.h"

int db = 1;

#define dp  printf("db(%d)\n", db++);




FILE *fopen_try(char *filename, char *mod, int *rc)
{

    FILE *result = fopen(filename, mod);

    if (!result)
        *rc = FOPEN_ERROR;

    return result;
}


double **get_mtr_2(FILE *f, int *row, int *col, int *rc)
{
db = 1;
    assert(f);

dp
    int n;
    double **result = NULL;

dp
    int r, c;
    double val;


dp
    if (fscanf(f, "%d%d%d", row, col, &n) != 3)
    {
        *rc = WRONG_INPUT;
        return result;
    }

dp

    if (!*rc)
        result = alloc_matrix(*row, *col);


dp
    if (!*rc && result)
    {
        *rc = ALLOCATION_ERROR;
        return result;
    }

dp
    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%d%d%lf", &r, &c, &val) != 3
            || r > *row || c > *col)
        {
            *rc = WRONG_INPUT;
            return result;
        }


        result[r - 1][c] = val;
    }

dp

    return result;
}









double **alloc_matrix(int row, int col)
{
    double **result = malloc(row * sizeof(size_t) + row * col * sizeof(double));


    if (!result)
        return result;

    double *prow = (double *)(result + row);

    for (int i = 0; i < row; i++, prow += col)
        result[i] = prow;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = 0.0;

    return result;
}



void put_mtr(FILE *f, double **mtr, int row, int col)
{
    assert(f);

    fprintf(f, "%d %d\n", row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            fprintf(f, "%lf%s", mtr[i][j], (j + 1)%col == 0 ? "\n" : " ");

}

    

        








