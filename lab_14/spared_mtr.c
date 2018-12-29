#include <stdlib.h>
#include "mtr.h"

typedef struct list_node list_node;

typedef struct mtr mtr_t;
struct mtr
{
    int len, wid;
    list_node **mtr;
};

typedef struct list_node list_node;
struct list_node
{
    int col;
    mtr_el val;
    list_node *next;
};



#define MTR(mtr_t)  ((mtr_t)->mtr)
#define YES         1
#define NO          0  


mtr_t *create(int len, int wid)
{
    mtr_t *result = malloc(sizeof(mtr_t));
    if (!result)
        return NULL;

    MTR(result) = calloc(sizeof(list_node *), len);

    if (! MTR(result) )
    {
        free(result);
        return NULL;
    }

    result->len = len;
    result->wid = wid;

    return result;
}


int mtr_set(mtr_t *mtr, int raw, int col, mtr_el val)
{
    if (! ((0 <= raw && raw < mtr->len) ||
           (0 <= col && col < mtr->wid)) )
        return OUT_OF_RANGE;

    if (!val)
        return HAPPY_END;

    if (MTR(mtr)[raw]->col == col)
    {
        MTR(mtr)[raw]->val = val;
        return HAPPY_END;
    }

    list_node *new = malloc(sizeof(list_node));
    if (!new)
        return ALLOCATION_E;

    new->col = col;
    new->val = val;
    new->next = NULL;

    if (MTR(mtr)[raw] == NULL)
    {
        MTR(mtr)[raw] = new;
        return HAPPY_END;
    }

    if (MTR(mtr)[raw]->col > col)
    {
        new->next = MTR(mtr)[raw];
        MTR(mtr)[raw] = new;
        return HAPPY_END;
    }

    list_node *par = MTR(mtr)[raw];
    list_node *iter = par->next;

    while (iter->col > col)
    {
        par = iter;
        iter = iter->next;
    }

    if (iter->col == col)
    {
        iter->val = val;
        free(new);
        return HAPPY_END;
    }

    par->next = new;
    new->next = iter;
    return HAPPY_END;
}



int mtr_get(mtr_t *mtr, int raw, int col, mtr_el *cont)
{
    if (! ((0 <= raw && raw < mtr->len) ||
           (0 <= col && col < mtr->wid)) )
        return OUT_OF_RANGE;

    list_node *iter = MTR(mtr)[raw];

    while (iter && iter->col < col)
    {
        iter = iter->next;
    }


    if (iter == NULL)
    {
        *cont = 0;
        return HAPPY_END;
    }


    if (iter->col > col)
    {
        *cont = 0;
        return HAPPY_END;
    }

    //if (iter->col == col)
    *cont = MTR(mtr)[raw]->val;

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
    if (can_be_added == NO)
        return BAD_ADD_SIZE;

    mtr_t *out = mtr_create(mtr1->len, mtr1->wid);
    if (!out)
        return ALLOCATION_E;

    for (int i = 0; i < mtr1->len; i++)
        for (int j = 0; j < mtr1->wid; j++)
        {
            mtr_el el1;
            mtr_el el2;

            mtr_get(mtr1, i, j, &el1);
            mtr_get(mtr2, i, j, &el2);

            mtr_set(out, i, j, el1 + el2);
        }

    mtr_free(*result);
    *result = out;

    return HAPPY_END;
}

static int can_be_multed(mtr_t *mtr1, mtr_t *mtr2)
{
    if (mtr1->wid != mtr2->len)
        return NO;
}

static void minit(mtr_t *mtr, mtr_el val)
{
    for (int i = 0; i < mtr->len; i++)
        for (int j = 0; j < mtr->wid; j++)
        {
            mtr_set(mtr, i, j, val);
        }
}

int mtr_mult(mtr_t *mtr1, mtr_t *mtr2, mtr_t **result)
{
    if (can_be_multed == NO)
        return BAD_MUL_SIZE;

    mtr_t *out = mtr_create(mtr1->len, mtr2->wid);
    if (!out)
        return ALLOCATION_E;

    minit(out, 0);

    for (int i = 0; i < mtr1->len; i++)
        for (int j = 0; j < mtr2->wid; j++)
        {
            mtr_el sum = 0;

            for (int k = 0; k < mtr1->wid; k++)
            {
                mtr_el el1;
                mtr_el el2;

                mtr_get(mtr1, i, j, &el1);
                mtr_get(mtr2, i, j, &el2);

                sum += el1 * el2;
            }
            
            mtr_set(out, i, j, sum);
        }
 
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








