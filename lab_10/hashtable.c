#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "headers/define.h"
#include "headers/colours.h"
#include "headers/hashtable.h"
#include "headers/listfunc.h"

#define START_SIZE  5
#define MAX_OCCUP   1.5
#define NEED_RESIZE 5


static int is_prime(int num);
static int next_prime(int prime);
static int hash(void *, hash_t *);
static int check_occup_koeff(hash_t *ht, float max_occup);
static hash_t *ht_resize(hash_t *ht);




// Hash Table CREATE
hash_t *ht_create(int start_size)
{
    if (start_size < 0)
        return NULL;

    if (start_size == 0)
        start_size = START_SIZE;

    hash_t *result = malloc(sizeof(struct hashtable));

    node_t **table = calloc(sizeof(node_t *), start_size);

    if (result == NULL || table == NULL)
        return NULL;

    result->size = 0;
    result->hashnum = start_size;
    result->table = table;

    return result;
}


// Hash Table ADD
int ht_add(hash_t **ht, void *data)
{
    int rc = ALL_GOOD;

    assert(ht);

    if (!data)
        return WRONG_DATA;

    hash_t *ht_ptr = *ht;

    int hashcode = hash(data, ht_ptr);

    if ((rc = add_front(ht_ptr->table + hashcode, data)) != HAPPY_END)
        return rc;

    ht_ptr->size += 1;

    if (check_occup_koeff(ht_ptr, MAX_OCCUP) == TRUE)
    {
        if ((ht_ptr = ht_resize(*ht)) != NULL)
            *ht = ht_ptr;
    }

    return rc;
}

// Hash Table HAS DATA
int ht_has_data(hash_t **ht, void *data)
{
    hash_t *ht_ptr = *ht;

    int resize_counter = 0;
    int hashcode = hash(data, ht_ptr);

    node_t *node = *(ht_ptr->table + hashcode);

    while (node)
    {
        if (resize_counter > NEED_RESIZE)
        {
            if ((ht_ptr = ht_resize(ht_ptr)) != NULL)
            {
                *ht = ht_ptr;
                return ht_has_data(ht, data);
            }

            ht_ptr = *ht;
        }


        if (node->data == data)
            return TRUE;

        node = node->next;

        resize_counter++;
    }

    return FALSE;
}

// Hash Table PRINT
void ht_print(hash_t *ht, char *name)
{
    float ht_occup = (float) ht->size / (float) ht->hashnum;

    printf("%s\n\nХэш-таблица %s'%s'%s:\n", BLUE, END_C YELLOW, name, END_C);

    printf("Кол-во элементов = %d\n", ht->size);

    printf("Число возможных хэшей = %d\n", ht->hashnum);

    printf("Текущая заполненность = %.2f\n", ht_occup);

    printf("\nСама таблица:\n");
    printf("Хэш | элементы\n");

    for (int i = 0; i < ht->hashnum; i++)
    {
        printf("%4d| ", i);

        node_t *cur_node = *(ht->table + i);

        while (cur_node != NULL)
        {
            printf("%p, ", cur_node->data);

            cur_node = cur_node->next;
        }

        printf("\n");
    }
}





// Hash Table FREE
void ht_free(hash_t **ht)
{
    hash_t *ht_ptr = *ht;

    for (int i = 0; i < ht_ptr->size; i++)
    {
        node_t *cur_node = *(ht_ptr->table + i);

        while (cur_node->next != NULL)
        {
            node_t *tmp = cur_node->next;
            free(cur_node);
            cur_node = tmp;
        }

        free(cur_node);
    }

    free(*ht);

    *ht = NULL;
}


// --> Внутренние ф-ии <-- //

static int hash(void *data, hash_t *ht)
{
    return (long long)data % ht->hashnum;
}


static int check_occup_koeff(hash_t *ht, float max_occup)
{
    float ht_occup = (float) ht->size / (float) ht->hashnum;

    if (ht_occup > max_occup)
        return TRUE;

    return FALSE;
}


static int next_prime(int prime)
{
    while (is_prime(++prime) != TRUE);

    return prime;
}


static int is_prime(int num)
{
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return FALSE;

    return TRUE;
}


static hash_t *ht_resize(hash_t *ht)
{
    hash_t *result = ht_create(next_prime(ht->hashnum));

    if (!result)
        return NULL;

    for (int i = 0; i < ht->hashnum; i++)
    {
        node_t *cur_node = *(ht->table + i);

        while (cur_node != NULL)
        {
            if (ht_add(&result, cur_node->data) != HAPPY_END)
            {
                ht_free(&result);
                return NULL;
            }

            cur_node = cur_node->next;
        }
    }

    return result;
}

