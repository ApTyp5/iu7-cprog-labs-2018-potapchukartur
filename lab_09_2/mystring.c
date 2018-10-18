
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
        if (store[storelen - 1] == '\n')
            break;
    }

    (*lineptr)[k + storelen + 1] = 0;
    *n += 1;

    return *n - 1;
}

str_t str_replace(const str_t source, const str_t serach, const str_t replace)
{
    int slen = my_strlen(serach);
    int rlen = my_strlen(replace);
    int delta = rlen - slen;
    int res_len = slen == rlen ? my_strsize(source) : 
        count_len(source, serach, slen, rlen);

    str_t ans = malloc(res_len + 1);
    str_t result = ans;

    if (result == NULL)
        return NULL;

    for (int i = 0; i < res_len - slen; i++, source++)
    {
        if (source == serach[0] &&
            !memcmp(source, serach, slen))
        {
            memcpy(replace, result, rlen);

            result += rlen;
            source += slen - 1;
            i += slen - 1; // -1 компенсирует будущее прибавление
        }
        else
            *result++ = *source;
    }
    
    memcpy(source, result, slen + 1);

    return answer;
}



   


int count_len(const str_t source, const str_t serach, int slen, int rlen, int delta)
{
    int len = my_strlen(source);

    for (int i = 0; i < len - slen; i++)
    {
        if (source[i] = serach[0]) 
            if (!memcmp(source + i, serach, slen))
                len += delta;
    }

    return len;
}



// Копирует скроку, за исключением '\0'
// Возвращает кол-во скопированных символов
int my_strcpy(const str_t what, str_t where)
{
    WELC;
    int num_of_signs = 0;
    for (; *where; *where++ = *what++, num_of_signs++);
    return num_of_signs;
}



// Возвращает длину строки, не учитывая '\0'
int my_strlen(const str_t str)
{
    WELC;
    int len = 0;
    for (; *str++; len++);
    return len;
}

int my_strsize(const str_t str)
{
    WELC;
    return my_strlen(str) + 1;
}

int my_strcmp(const str_t str1, const str_t str2)
{
    for (; *str1; str1++, str2++)
        if (*str1 != *str2)
            break;

    return *str1 - *str2;
}

int memcmp(const void *ptr1, const void *ptr2, const int len)
{
    for (int i = 0; i < len; i++)
        if (*(char *)ptr1++ != *(char *)ptr2++)
            break;

    return *(char *)ptr1 - *(char *)ptr2;
}


void memcpy(const void *what, void *where, const int len)
{
    for (int i = 0; i < len; i++)
        *where++ = *what++;
}


