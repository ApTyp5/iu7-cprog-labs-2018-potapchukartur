#include <stdio.h>
#include <stdlib.h>
#include "headers/darriu7.h"


/*  Создание дин. массива длины len  */
/*************************************/
// --> Вход : длина массива
// --> Выход: указатель на начало массива при успешном
// выделении памяти и корректности входных даннх, 
// NULL иначе
darriu7 darriu7_create(int len)
{
    if (len  < 0) 
        return NULL;

    if (len == 0)
        len = INITIAL_SIZE;

    darriu7 darr; 

    if ((darr= malloc((len + PRIVAT_DATA_SIZE) * sizeof(int))) == NULL)
        return NULL;

    *darr++ = len; 
    *darr++ = 0;

    // Итог:
    // darr[-1] = CUR_LEN
    // darr[-2] = MAX_LEN

    return darr;
}

/*  Вывод текущей дины      */
/****************************/
// --> Вход : дин. массив
// --> Выход: длина массива
// в случае корректных данных,
// IU7_FAIL иначе
int darriu7_len(darriu7 darr)
{
    if (!darr)
        return IU7_FAIL;
    
    return CUR_LEN;
}

/*  Вывод coдержимого динамического массива на экран  */
/******************************************************/
// --> Вход : дин. массив
void darriu7_print(darriu7 darr)
{
    printf("[");

    for(int i = 0; i < CUR_LEN; i++)
    {
        printf("%d ", darr[i]);
    }

    for(int i = CUR_LEN; i < MAX_LEN; i++)
    {
        printf("* ");
    }

    printf("]\n");
}

/* Добавление элемента в конец дин. массива  */
/*********************************************/
// --> Вход : дин. массив, значение элемента,
// который хотим добавить
// --> Выход: адрес получившегося дин. массива.
darriu7 darriu7_append(darriu7 darr, int x)
{

    if(CUR_LEN == MAX_LEN)
    {
        int old_max_len = MAX_LEN;
        int old_cur_len = CUR_LEN;

        darr = realloc(darr - PRIVAT_DATA_SIZE, 
            (2 * MAX_LEN + PRIVAT_DATA_SIZE) * sizeof(int));
        if (!darr)
            return NULL;

        // Если не понятно, что написано внизу, смотри ф-ю create
        *darr++ = 2 * old_max_len;
        *darr++ = old_cur_len;
    }
    
    darr[CUR_LEN++] = x;

    return darr;
}


/* Освобождение памяти из-под дин. массива */
/*******************************************/
// --> Вход: дин. массив.
void darriu7_release(darriu7 darr)
{
    free(darr - PRIVAT_DATA_SIZE);
}



