
#include <stdlib.h>
#include "inout.h"
#include "define.h"




int fopen_try(file_t *f, str_t fname, str_t mod)
{
    *f = fopen(fname, mod);
    if (!*f)
        return FOPEN_ERROR;

    return HAPPY_END;
}
    


int read_mtr(str_t fname, matrix_t *mtr, int *len, int *wid,
    int get_mtr(file_t, matrix_t *, int *len, int *wid))
{
    int rc = HAPPY_END;
    file_t f = NULL;

    rc = fopen_try(&f, fname, "r");

    if (!rc)
        rc = get_mtr(f, mtr, len, wid);

    if (!rc)
        rc = fclose(f); // rc = EOF, если произошла ошибка

    return rc;
}


// Второй метод считывания матрицы
int get_mtr_m2(file_t f, matrix_t *mtr, int *len, int *wid)
{
    int n;
    if (fscanf(f, "%d%d%d", len, wid, &n) != 3)
        return WRONG_INPUT;

    *mtr = allocate_matrix(*len, *wid);
    zero_identify(mtr, *len, *wid);

    int raw, col;
    double val;

    for (int i = 0; i < n; i++)
    {
        if (fscanf(f, "%d%d%lf", &raw, &col, &val) != 3 &&
            0 < raw && raw <= *len &&
            0 < col && col <= *wid)
            return WRONG_INPUT;
        (*mtr)[raw - 1][col - 1] = val;
    }

    return HAPPY_END;
}



matrix_t allocate_matrix(int len, int wid)
{
    matrix_t result = malloc(sizeof(double **) * len + len * wid * sizeof(double));

    if (!result)
        return NULL;

    char *tmp =  (char *)result + len * sizeof(double *);
    for (int i = 0; i < len; i++, tmp += sizeof(double) * wid)
        result[i] = (double *)tmp;

    return result;
}

void zero_identify(matrix_t *mtr, int len, int wid)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
            (*mtr)[i][j] = 0.0;
}


int write_mtr(str_t fname, matrix_t mtr, int len, int wid,
    void put_mtr(file_t, matrix_t, int len, int wid))
{
    int rc = HAPPY_END;
    file_t f = NULL;

    rc = fopen_try(&f, fname, "w");

    if (!rc)
    {
        put_mtr(f, mtr, len, wid);
        rc = fclose(f); // rc == EOF, если произошла ошибка
    }

    return rc;
}


void put_mtr_m1(file_t f, matrix_t mtr, int len, int wid)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
        {
            fprintf(f, "%6lf%s", mtr[i][j], (j + 1)%wid ? " " : "\n");
        }
}





   
