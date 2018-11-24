#include "list.h"
#include "mtr.h"
#include <stdlib.h>





list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid)
{
    list_node **lista = malloc(sizeof(list_node) * len); // LIST A
    int tmp;


    if (!lista)
        return NULL;

    for (int i = 0; i < len; i++)
        (lista[i])->next = NULL;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            if (mtr[i][j] != 0)
            {
                list_node **last = behind_last_in_raw(lista[i], &tmp); // указ на NULL
                if (((*last)->next = malloc(sizeof(list_node))) != NULL)
                {
                    (*last)->next->col = j;
                    (*last)->next->val = i;
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

    list_node **end_ptr = malloc(sizeof(list_node *));
    if (!end_ptr)
        return NULL;


    while (now != NULL)
    {
        *len_of_raw += 1;
        now = now->next;
    }

    return end_ptr = &now;
}






