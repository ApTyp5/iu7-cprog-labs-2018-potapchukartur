
#include <stdlib.h>
#include "define.h"
#include "hashtable.h"
#include "listfunc.h"

#define START_SIZE  10

static int hash(void *, int );


hash_t *ht_create()
{
    hash_t *result = malloc(sizeof(struct hashtable));

    node_t *table = malloc(sizeof(node_t) * START_SIZE);

    if (result == NULL || table == NULL)
        return NULL;

    result->curnum = 0;
    result->hashnum = START_SIZE;
    result->table = table;

    return result;
}


int ht_add(hash_t *ht, void *data)
{
    if (!ht || !data)
        return WRONG_DATA;

    int hashcode = hash(data, ht->hashnum);
    node_t *node = ht->table + hashcode;

    int rc = add_front(&node, data);

    ht->curnum += 1;

    return rc;
}

int ht_has_data(hash_t *ht, void *data)
{
    int hashcode = hash(data, ht->hashnum);

    node_t *node = (ht->table) + hashcode;

    while (node)
    {
        if (node->data == data)
            return TRUE;

        node = node->next;
    }

    return FALSE;
}



static int hash(void *data, int hashnum)
{
    return (long long)data % hashnum;
}


