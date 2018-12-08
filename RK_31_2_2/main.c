#include <stdio.h>
#include "define.h"
#include "mtr.h"
#include "list.h"


void exersize_9(list_node **, int, int);

void pmtr(mtr_t mtr, int len, int wid)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < wid; j++)
            printf("%d%s", mtr[i][j], (j + 1) % len ? " " : "\n");
}

void plista(list_node **larr, int len, int wid)
{
    for (int i = 0; i < len; i++)
    {
        list_node *raw = larr[i];

        for (int j = 0; j < wid; j++)
        {
            if (raw && j == raw->col)
            {
                printf("%d ", raw->val);
                raw = raw->next;
            }
            else
                printf("0 ");
        }
    }
}

int main(int ac, char **av)
{
    int rc = ALL_GOOD;
    int len, wid;


    mtr_t mtr = NULL;

    rc = mtr_readMM(&mtr, av[1], &len, &wid);
pmtr(mtr, len, wid);
printf("\n");

    list_node **lista = convert_mtr_to_lista(mtr, len, wid);
plista(lista, len, wid);

    exersize_9(lista, len, wid);

    mtr_free(mtr);
    // Освоб мас списк 
    
    return rc;
}





void exersize_9(list_node **lista, int len, int wid)
{
    return;
}





