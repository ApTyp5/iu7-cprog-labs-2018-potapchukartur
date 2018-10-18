
#include <stdlib.h>
#include "aplog.h"
#include "define.h"
#include "mystring.h"


// Проверка на сущетсвование/открытие потока отстется за пользователем
ssize_t my_getline(char **lineptr, size_t *n, file_t stream)
{
    WELC;
    char store[BUFFSIZE + 1];
    int storelen = 0;
    int k = 0;

    if (*lineptr == NULL || *n == 0)
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
            *lineptr = realloc(*lineptr, k + BUFFSIZE + 1);
            *n = k + BUFFSIZE;
            if (*lineptr == NULL)
                return ALLOCATION_ERROR;
        }

        my_strcpy(store, *lineptr + k);
        if (store[storelen - 1] == '\n')
            break;
    }

    if (k + storelen == 0)

    (*lineptr)[k + storelen + 1] = 0;
    *n += 1;

    return *n - 1;
}

char *str_replace(const char *source, const char *serach, const char *replace)
{
    WELC;
    int slen = my_strlen(serach);
    int rlen = my_strlen(replace);
    int delta = rlen - slen;
    int res_len = slen == rlen ? my_strsize(source) : 
        count_len(source, serach, slen, rlen, delta);

    char *ans = malloc(res_len + 1);
    char *result = ans;

    if (result == NULL)
        return NULL;

    for (int i = 0; i < res_len - slen; i++, source++)
    {
        if (*source == serach[0] &&
            !my_memcmp(source, serach, slen))
        {
            my_memcpy(replace, result, rlen);

            result += rlen;
            source += slen - 1;
            i += slen - 1; // -1 компенсирует будущее прибавление
        }
        else
            *result++ = *source;
    }
    
    my_memcpy(source, result, slen + 1);

    return ans;
}



void fs_printf(file_t f, char *str)
{
    WELC;

    char tmp;

    while ((tmp = *str++))
        fprintf(f, "%c", tmp);
}

   


int count_len(const char *source, const char *serach, int slen, int rlen, int delta)
{
    WELC;
    int len = my_strlen(source);

    for (int i = 0; i < len - slen; i++)
    {
        if (source[i] == serach[0]) 
            if (!my_memcmp(source + i, serach, slen))
                len += delta;
    }

    return len;
}



// Копирует скроку, за исключением '\0'
// Возвращает кол-во скопированных символов
int my_strcpy(const char *what, char *where)
{
    WELC;

    int num_of_signs = 0;
    for (; *where; num_of_signs++)
        *where++ = *what++;

    return num_of_signs;
}



// Возвращает длину строки, не учитывая '\0'
int my_strlen(const char *str)
{
    WELC;
    int len = 0;
    for (; *str++; len++);
    return len;
}

int my_strsize(const char *str)
{
    WELC;
    return my_strlen(str) + 1;
}

int my_strcmp(const char *str1, const char *str2)
{
    WELC;
    for (; *str1; str1++, str2++)
        if (*str1 != *str2)
            break;

    return *str1 - *str2;
}

int my_memcmp(const void *ptr1, const void *ptr2, const int len)
{
    WELC;
    for (int i = 0; i < len; i++)
        if (*(char *)ptr1++ != *(char *)ptr2++)
            break;

    return *(char *)ptr1 - *(char *)ptr2;
}


void my_memcpy(const void *what, void *where, const int len)
{
    WELC;
    for (int i = 0; i < len; i++)
        *(char *)where++ = *(char *)what++;
}




