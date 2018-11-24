#include "list.h"
#include "mtr.h"
#include <stdlib.h>





list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid)
{
    list_node **lista = malloc(sizeof(list_node) * len); // LIST A

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
                list_node *last = last_in_raw(lista[i]);
                if ((last->next = malloc(sizeof(list_node))) != NULL)
                {
                    last->next->col = j;
                    last->next->val = i;
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



list_node *last_in_raw(list_node *raw)
{
    list_node *now = raw;
    while (now->next != NULL)
        now = now->next;

    return now;
}






