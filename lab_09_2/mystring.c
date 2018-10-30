#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mystring.h"
#include "define.h"
#include "debug.h"

char *my_strrchr(const char *lineptr, int c);



// Ленивый strcmp, без проверок, без максимальной длины
int lazy_strcmp(const char *str_1, const char *str_2)
{
    for (; *str_1 == *str_2; str_1++, str_2++)
        if (*str_1 * (*str_2) == 0)
            break;

    return *str_1 - *str_2;
}

ssize_t my_fgets(char *lineptr, size_t size, FILE *stream)
{
    fgets(lineptr, size, stream);
    ssize_t len = my_strrchr(lineptr, 0) - (char *)lineptr;

    return len;
}


int my_strncmp(const char *str_1, const char *str_2, int n)
{
    for (int i = 1; i < n; i++, str_1++, str_2++)
        if (*str_1 != *str_2)
            break;

    return *str_1 - *str_2;
}

int lazy_strcpy(const char *what, char *where)
{
    int len = 0;

    for (len = 0; (*where++ = *what++); len++);
    return len;
}


ssize_t my_getline(char **lineptr, size_t *size, FILE *stream)
{
    ssize_t len;
    char buf[BSIZE];




    if (*lineptr == NULL || *size == 0)
        if(!(*lineptr = realloc(NULL,  (*size = BSIZE))))
            return ALLOC_ERROR;


    len = my_fgets(*lineptr, *size, stream);
    if (len + 1 < *size)
        return len;


    while((my_fgets(buf, BSIZE, stream) > 0))
    {
        *size += BSIZE - 1;
        if (!realloc(*lineptr, *size))
            return ALLOC_ERROR;

        lazy_strcpy(buf, *lineptr + len);
        len = my_strrchr(*lineptr, 0) - *lineptr;

        if (len + 1 < *size)
            break;
    }


    return len;
}



char *my_strreplace(const char *source, const char *ser, const char *rep)
{
    if (!source)
        return NULL;
    if (!ser)
        return NULL;
    if (!rep)
        return NULL;


    int serlen = my_strrchr(ser, 0) - ser;
    int replen = my_strrchr(rep, 0) - rep;

    
    int reslen = count_res_len(source, ser, serlen, replen);



    char *res = malloc(reslen + 1); 
    if (!res)
        return NULL;

    char *ans = res;
    res[reslen] = 0;

    for (int len = 0; len < reslen; )
        if (!my_strncmp(ser, source, serlen))
        {
            lazy_strcpy(rep, ans);
            source += serlen;
            ans += replen;
            len += replen;
        }
        else
        {
            *ans++ = *source++;
            len++;
        }


    return res;
}



int count_res_len(const char *source, const char *ser, int serlen, int replen)
{
    int len;
    for (len = 0; *source;)
        if (!my_strncmp(ser, source, serlen))
        {
            len += replen; 
            source += serlen; 
        }
        else
        {
            len++;
            source++;
        }

    return len;
}


char *my_strdup(const char *str)
{
    int strlen = my_strrchr(str, 0) - str;
    char *res = malloc(strlen + 1);
    if (!res)
        return NULL;

    res[strlen] = 0;
    lazy_strcpy(str, res);

    return res;
}




