#include "list.h"
#include "mtr.h"
#include <stdlib.h>





list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid)
{
    list_node **lista = malloc(sizeof(list_node *) * len); // LIST A
    int tmp;


    if (!lista)
        return NULL;

    for (int i = 0; i < len; i++)
        lista[i] = NULL;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            if (mtr[i][j] != 0)
            {
                list_node **last = behind_last_in_raw(lista[i], &tmp); // указ на NULL
                if (((*last) = malloc(sizeof(list_node*))) != NULL)
                {
                    (*last)->col = j;
                    (*last)->val = i;
                }
                else
                {
                    free(lista);
                    return NULL;
                }
            }
        }
    }


    return lista;
}




list_node **behind_last_in_raw(list_node *now, int *len_of_raw)
{
    *len_of_raw = 0;

    while (now != NULL)
    {
        *len_of_raw += 1;
        now = now->next;
    }

    list_node **lptr = malloc(sizeof(list_node *));

    if (!lptr)
        return NULL;

    return lptr = &now;
}






