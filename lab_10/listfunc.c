#include <stdio.h>
#include <stdlib.h>
#include "listfunc.h"
#include "define.h"


// ADD node in FRONT
int add_front(node_t **head, void *data)
{
    // *head может быть == NULL, 
    // тогда ф-я "создает" список

    if (head == NULL)                          
        return WRONG_DATA_REC;

    if (data == NULL)
        return WRONG_DATA_REC;


    node_t *new = malloc(sizeof(node_t));

    if (!new)
        return ALLOC_ERROR;

    new->data = data;
    new->next = *head;

    *head = new;

    return HAPPY_END;
}


// possed
void *pop_front(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;
    void *data_ptr = (*head)->data;
    node_t *need_to_free = *head;

    *head = (*head)->next;

    free(need_to_free);

    return data_ptr;
}


// passed
node_t *find(node_t *head, const void *data,
    int comparator(const void *, const void *))
{
    while (head)
    {
        if (comparator(head->data, data) == EQ)
            return head;

        head = head->next;
    }

    return NULL;
}


void *pop_nonfront(node_t *cur, node_t *prev)
{
    if (!prev || !cur)
    {
        return NULL;
    }

    void *data = cur->data;

    prev->next = cur->next;
    free(cur);

    return data;
}



void remove_duplicates(node_t **head, 
    int comparator(const void *, const void *))
{
    if (head == NULL)
        return;

    while (1)
    {
        if ((*head) == NULL ||
            (*head)->next == NULL)
            return;

        if ((*comparator)((*head)->data, (*head)->next->data) == EQ)
            pop_front(head);
        else
            break;
    }

    node_t *cur = (*head)->next;

    if (cur == NULL)
        return;

    while (cur->next != NULL)
    {
        node_t *next = cur->next;

        if ((*comparator)(cur->data, next->data) == EQ)
        {
            cur->next = next->next;
            free(next);
            continue;
        }
        cur = cur->next;
    }

}


int llen(node_t *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}



// passed (with mem errors)
void front_back_split(node_t *head, node_t **back)
{
    if (!back && !head)
        return;

    *back = head;

    int len = llen(head);
    if (len <= 1)
        return;

    int num_of_steps = (len & 1) + (len >> 1); // len%2 + len/2


    for (int i = 0; i < num_of_steps - 1; i++)
        *back = (*back)->next;

    node_t *el = *back;
    
    *back = (*back)->next;

    el->next = NULL;
}


    



node_t *sorted_merge(node_t **head_a, node_t **head_b,
    int comparator(const void *, const void *))
{
    if (head_a == NULL || head_b == NULL)
        return NULL;

    node_t *cur_a = *head_a;
    node_t *cur_b = *head_b;

    node_t *result;

    while (cur_a && cur_b)
    {
        if (comparator(cur_a->data, cur_b->data) < 0)
        {
            if ((add_front(&result, cur_a->data)) == ALLOC_ERROR)
            {
                free_list(result);
                return NULL;
            }
            cur_a = cur_a->next;
            continue;
        }

        if ((add_front(&result, cur_b->data)) == ALLOC_ERROR)
        {
            free_list(result);
            return NULL;
        }
        cur_b = cur_b->next;
    }

    while (cur_a)
    {
        if ((add_front(&result, cur_a->data)) == ALLOC_ERROR)
        {
            free_list(result);
            return NULL;
        }
        cur_a = cur_a->next;
    }

    while (cur_b)
    {
        if ((add_front(&result, cur_b->data)) == ALLOC_ERROR)
        {
            free_list(result);
            return NULL;
        }
        cur_b = cur_b->next;
    }

    return result;
}


int list_extend();


int comp_add_front();





void free_list(node_t *head)
{
    while (1)
    {
        if (head == NULL)
            return;

        node_t *tmp = head->next;
        free(head);
        head = tmp;
    }
}































