#include <stdio.h>
#include <stdlib.h>
#include "headers/fileworks.h"
#include "headers/mtr.h"
#include "headers/define.h"



mtr_t mtr_create(int len, int wid)
{
    mtr_t mtr = malloc(len * sizeof(int *) + len * wid * sizeof(int));

    if (!mtr)
        return NULL;

    for (int i = 0; i < len; i++)
        mtr[i] = (int *)((char *)mtr + len * sizeof(int *) + i * wid * sizeof(int));

    return mtr;
}

void mtr_free(mtr_t mtr)
{
    free(mtr);
}


// Пока без проверок
int mtr_readMM(mtr_t *mtr, char *fnam, int *len, int *wid)
{
    int rc = ALL_GOOD;

    FILE *f = fopen_try(fnam, "r", &rc);

    if (rc != ALL_GOOD)
        return rc;

    int nonull;

    fscanf(f, "%d%d%d", len, wid, &nonull);

    if ((*mtr = mtr_create(*len, *wid)) == NULL)
        return ALLOC_ERROR;

    for (int i = 0; i < nonull; i++)
    {
        int raw, col, val;
        fscanf(f, "%d%d%d", &raw, &col, &val);

        (*mtr)[raw - 1][col - 1] = val;
    }

    return rc;
}




