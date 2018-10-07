#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "define.h"
#include "inout.h"

int db = 1;

#define dp  printf("db(%d)\n", db++);


double **read_matr(char *fname, int *len, int *wid, int *rc)
{
    double **answer = NULL;
    FILE *f = fopen_try(fname, "r", rc);

    if (!*rc)
        answer = get_mtr_2(f, len, wid, rc);

    if (!*rc)
        *rc = fclose(f);

    return answer;
}
    



FILE *fopen_try(char *filename, char *mod, int *rc)
{

    FILE *result = fopen(filename, mod);

    if (!result)
        *rc = FOPEN_ERROR;

    return result;
}


double **get_mtr_2(FILE *f, int *row, int *col, int *rc)
{
    assert(f);

    int n;
    double **result = NULL;

    int r, c;
    double val;


    if ((fscanf(f, "%d%d%d", row, col, &n) != 3))
    {
        *rc = WRONG_INPUT;
        return result;
    }



    if (!*rc)
        result = alloc_matrix(*row, *col);


    if (!*rc && !result)
    {
        *rc = ALLOCATION_ERROR;
        return result;
    }

    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%d%d%lf", &r, &c, &val) != 3
            || r > *row || c > *col)
        {
            *rc = WRONG_INPUT;
            return result;
        }


        result[r - 1][c - 1] = val;
    }

    return result;
}






double **alloc_matrix(int row, int col)
{
    double **result = malloc(row * sizeof(size_t) + row * col * sizeof(double));


    if (!result)
        return result;

    double *prow = (double *)((char *)result + row * sizeof(size_t));

    for (int i = 0; i < row; i++, prow += col * sizeof(double))
        result[i] = prow;


    return result;
}



void put_mtr_1(FILE *f, double **mtr, int row, int col)
{
    assert(f);

    fprintf(f, "%d %d\n", row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            fprintf(f, "%lf%s", ((double (*)[col])mtr)[i][j], (j + 1)%col == 0 ? "\n" : " ");

}












