
#include "hashtable.h"
#include "listfunc.h"


hash_t *ht_create()
{
    hash_t *result = malloc(sizeof(struct hashtable));

    if (result == NULL)
        return NULL;

    result->curnum = 0;
    result->maxnum = DEFAULT_MAXNUM;

    return result;
}


int ht_add(hash_t *ht, void *data)
{




