#ifndef __LISTM_H__
#define __LISTM_H__

#include <stdlib.h>
#include "list.h"
#include "mtr.h"



typedef struct list_node list_node;


struct list_node
{
    int col;
    int val;

    list_node *next;
};




list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid);

list_node **behind_last_in_raw(list_node *raw, int *len_of_raw);

#endif


