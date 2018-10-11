
#include <stdlib.h>
#include "inout.h"
#include "define.h"
#include "aplog.h"




int fopen_try(file_t *f, str_t fname, str_t mod)
{
    PE;
    
    *f = fopen(fname, mod);
    if (!*f)
        return FOPEN_ERROR;

    return HAPPY_END;
}
    


int read_mtr(str_t fname, matrix_t *mtr, int *len, int *wid,
    int get_mtr(file_t, matrix_t *, int *len, int *wid))
{
    PE;



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
    PE;

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
    PE;
    matrix_t result = malloc(sizeof(double **) * len + len * wid * sizeof(double));

    if (!result)
        return NULL;

    double *tmp = (double *)result + len;
    for (int i = 0; i < len; i++, tmp += sizeof(double) * wid)
        result[i] = tmp;

    return result;
}

void zero_identify(matrix_t *mtr, int len, int wid)
{
    PE;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
            (*mtr)[i][j] = 0.0;
}


int write_mtr(str_t fname, matrix_t mtr, int len, int wid,
    void put_mtr(file_t, matrix_t, int len, int wid))
{
    PE;
    PIV("len = ", len);
    PIV("wid = ", wid);
    PM("fname : ");
    PM(fname);
    PM("\n");
    PMAT("out :\n", mtr, len, wid, " ");

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
    PE;
    PIV("len = ", len);
    PIV("wid = ", wid);
    PMAT("mtr :\n", mtr, len, wid, " ");
    PFV("mtr[1][0] = ", mtr[1][0]);

    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
        {
            if (i == 1 && j == 0)
                printf("cycle mtr[1][0] = %lf", mtr[1][0]);

            fprintf(f, "%lf%s", mtr[i][j], (j + 1)%wid ? " " : "\n");
        }
}





   
