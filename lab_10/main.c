#include <stdio.h>
#include <stdlib.h>
#include "headers/define.h"
#include "headers/hashtable.h"


int main()
{
    hash_t *ht = ht_create(10);
    int *my_int;

    ht_print(ht, "ht1");

    for (int i = 0; i < 10; i++)
    {
        my_int = malloc(sizeof(int));

        ht_add(&ht, my_int);
    }

    ht_print(ht, "ht1 with 10 el");


    for (int i = 0; i < 100; i++)
    {
        my_int = malloc(sizeof(int));

        ht_add(&ht, my_int);
    }

    ht_print(ht, "ht1 with 50 el");

    printf("has last el = %s\n", ht_has_data(&ht, my_int) == TRUE ? "True" : "False");

    return 0;
}

