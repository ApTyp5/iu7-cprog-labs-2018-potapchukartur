
#include "define.h"




int fopen_try(file_t *f, char *fname, char *mod)
{
    *f = fopen(fname, mod);
    if (!*f)
        return FOPEN_ERROR;

    return HAPPY_END;
}
    


int read_mtr(char *fname, matrix_t *mtr, int *len, int *wid,
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


int method_2(file_t f, matrix_t *mtr, int *len, int *wid)
{
    int raw, col, n;
    if (fscanf(f, "%d%d%d", &raw, &col, &n) != 3)
        return WRONG_INPUT;

    *mtr = allocate_matrix();
}








}

