#include <stdlib.h>
#include "mtr.h"


typedef struct mtr mtr_t;
struct mtr
{
    int len, wid;
    mtr_el **mtr;
};

#define MTR(mtr_t)  ((mtr_t)->mtr)
#define YES         1
#define NO          0  

static void minit(mtr_t *mtr, mtr_el val);

mtr_t *mtr_create(int len, int wid)
{
    mtr_t *result = malloc(sizeof(mtr_t));
    if (!result)
        return NULL;

    result->mtr = malloc(sizeof(mtr_el *) * len + 
                         sizeof(mtr_el)   * len * wid);
    if (! MTR(result) )
    {
        free(result);
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        MTR(result)[i] = (mtr_el *)((char *)MTR(result) + i * len * sizeof(mtr_el *));
    }

    minit(result, 0);

    result->len = len;
    result->wid = wid;

    return result;
}


int mtr_set(mtr_t *mtr, int raw, int col, mtr_el val)
{
    if (! ((0 <= raw && raw < mtr->len) ||
           (0 <= col && col < mtr->wid)) )
        return OUT_OF_RANGE;

    MTR(mtr)[raw][col] = val;

    return HAPPY_END;
}


int mtr_get(mtr_t *mtr, int raw, int col, mtr_el *cont)
{
    if (! ((0 <= raw && raw < mtr->len) ||
           (0 <= col && col < mtr->wid)) )
        return OUT_OF_RANGE;

    *cont = MTR(mtr)[raw][col];

    return HAPPY_END;
}


static int can_be_added(mtr_t *mtr1, mtr_t *mtr2)
{
    if (mtr1->len != mtr2->len)
        return NO;
    if (mtr1->wid != mtr2->wid)
        return NO;
    return YES;
}

int mtr_add(mtr_t *mtr1, mtr_t *mtr2, mtr_t **result)
{
    if (can_be_added(mtr1, mtr2) == NO)
        return BAD_ADD_SIZE;

    mtr_t *out = mtr_create(mtr1->len, mtr1->wid);
    if (!out)
        return ALLOCATION_E;

    for (int i = 0; i < mtr1->len; i++)
        for (int j = 0; j < mtr1->wid; j++)
            MTR(out)[i][j] = MTR(mtr1)[i][j] + MTR(mtr2)[i][j];

    mtr_free(*result);
    *result = out;

    return HAPPY_END;
}

static int can_be_multed(mtr_t *mtr1, mtr_t *mtr2)
{
    if (mtr1->wid != mtr2->len)
        return NO;
    return YES;
}

static void minit(mtr_t *mtr, mtr_el val)
{
    for (int i = 0; i < mtr->len; i++)
        for (int j = 0; j < mtr->wid; j++)
            MTR(mtr)[i][j] = val;
}

int mtr_mult(mtr_t *mtr1, mtr_t *mtr2, mtr_t **result)
{
    if (can_be_multed(mtr1, mtr2) == NO)
        return BAD_MUL_SIZE;

    mtr_t *out = mtr_create(mtr1->len, mtr2->wid);
    if (!out)
        return ALLOCATION_E;

    minit(out, 0);

    for (int i = 0; i < mtr1->len; i++)
        for (int j = 0; j < mtr2->wid; j++)
            for (int k = 0; k < mtr1->wid; k++)
                MTR(out)[i][j] += MTR(mtr1)[i][k] * MTR(mtr2)[k][j];

    mtr_free(*result);
    *result = out;
    return HAPPY_END;
}

void mtr_free(mtr_t *mtr)
{
    if (!mtr)
        return;

    free(MTR(mtr));
    free(mtr);
}








