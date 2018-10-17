
#include <stdlib.h>
#include "aplog.h"
#include "define.h"


// Проверка на сущетсвование/открытие потока отстется за пользователем
ssize_t my_getline(str_t *lineptr, size_t *n, file_t stream)
{
    WELC;
    char store[BUFFSIZE + 1];
    int storelen = 0;
    int k;

    if (*lineptr == NULL || *n = 0)
    {
        *n = BUFFSIZE;
        *lineptr = malloc(BUFFSIZE + 1); // Доп символ на 0
        if (*lineptr == NULL)
            return ALLOCATION_ERROR;
    }

    for (int i = 0; fgets(store, BUFFSIZE + 1, stream); i++)
    {
        k = i * BUFFSIZE;// Занятые ячейки буфера
        
        if ((storelen = my_strlen(store)) > *n - k)
        {
            realloc(*lineptr, k + BUFFSIZE + 1);
            *n = k + BUFFSIZE;
            if (*lineptr == NULL)
                return ALLOCATION_ERROR;
        }

        my_strcpy(store, *lineptr + k);
    }

    (*lineptr)[k + storelen + 1] = 0;
    *n += 1;

    return *n - 1;
}









}



// Копирует скроку, за исключением '\0'
// Возвращает кол-во скопированных символов
int my_strcpy(str_t what, str_t where)
{
    WELC;
    int num_of_signs = 0;
    for (; *where; *where++ = *what++, num_of_signs++);
    return num_of_signs;
}

// Возвращает длину строки, не учитывая '\0'
int my_strlen(str_t str)
{
    WELC;
    int len = 0;
    for (; *str++; len++);
    return len;
}

int my_strsize(str_t str)
{
    WELC;
    return my_strlen(str) + 1;
}


