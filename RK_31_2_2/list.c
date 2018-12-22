#include "headers/list.h"
#include "headers/define.h"
#include "headers/mtr.h"
#include <assert.h>
#include <stdlib.h>


list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid)
{
    assert(mtr);
    assert(len > 0);
    assert(wid > 0);


    list_node **lista = calloc(sizeof(list_node *), len); // LIST A


    if (!lista)
        return NULL;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            if (mtr[i][j] != 0)
            {
                if (add_back(lista, i, j, mtr[i][j]) == ALLOC_ERROR)
                {
                    free(lista);
                    return NULL;
                }
            }
        }
    }


    return lista;
}


int add_back(list_node **lista, int raw, int col, int val)
{
    assert(lista);
    assert(raw >= 0);
    assert(col >= 0);


    list_node *cur = lista[raw];

    if (cur != NULL)
    {
        for (; cur->next; cur = cur->next);

        cur->next = malloc(sizeof(list_node));
        if (!cur->next)
            return ALLOC_ERROR;

        cur->next->next = NULL;
        cur->next->col = col;
        cur->next->val = val;
    }
    else
    {
        lista[raw] = malloc(sizeof(list_node));
        if (!lista[raw])
            return ALLOC_ERROR;

        lista[raw]->next = NULL;
        lista[raw]->col = col;
        lista[raw]->val = val;
    }

    return HAPPY_END;
}


inline int max(int a, int b)
{
    return a > b ? a : b;
}


inline int min(int a, int b)
{
    return a < b ? a : b;
}


int friend_research(list_node **lista, int len, int comp(int , int))
{
    assert(lista);
    assert(len > 0);

    int friend_num = 0;
    int result_raw = 0;

    list_node *node = lista[0];
    while (node)
    {
        node = node->next;
        friend_num++;
    }

    
    for (int i = 1; i < len; i++)
    {
        int local_friend_num = 0;

        list_node *node = lista[i];
        
        while (node)
        {
            node = node->next;
            local_friend_num++;
        }

        if (comp(local_friend_num, friend_num) == local_friend_num)
        {
            friend_num = local_friend_num;
            result_raw = i;
        }
    }

    return result_raw;
}


int is_friend(list_node **lista, int len, int who, int whom) // Кто?, Чей?
{
    list_node *cur = lista[whom];

    while (cur)
    {
        if (cur->col == who)
            return YES;

        cur = cur->next;
    }

    return NO;
}








static void list_apply(list_node **lista, int len, void func(list_node *node))
{
    list_node *now = NULL;
    list_node *next = NULL;

    for (int i = 0; i < len; i++)
    {
        if (lista[i])
        {
            now = lista[i];

            while (now)
            {
                next = now->next;
                func(now);
                now = next;
            }
        }
    }
}

static void node_free(list_node *node)
{
    free(node);
}

void list_free(list_node **lista, int len)
{
    list_apply(lista, len, node_free);
}



