#include <stdarg.h>
#include <stdlib.h>
#include "define.h"


#define START_SIZE 20

char *int_to_str(int integ, int basis);
static char *retrievef(va_list vlist, char c);


int my_snprintf(char *restrict s, size_t n, const char *restrict fstr, ...)
{
    va_list vlist;
    va_start(vlist, fstr);


    int count = 0; 
    char *str_arg = NULL;

    while (*fstr != '\0')
    {
        if (*fstr == '%')
        {
            char c = *++fstr;

            if (c == 'h') // Учитываем модификатор
            {
                c = *++fstr;
            }

            str_arg = retrievef(vlist, c);
            int add = my_snprintf(s, n, str_arg);

            n -= add;
            s += add;
            count += add;

            if (c != 's')
                free(str_arg);

            str_arg = NULL;
            fstr++;

            continue;
        }

        if (n > 1)
        {
            *s++ = *fstr++;
            n--;
            count++;
            continue;
        }

        fstr++; // Если size == 0, то my_snprint возвратит длину строки
        count++;
    }

    if (s)
    {
        if (n > 1)
            *s = 0;
        else
            *++s = 0;
    }

    return count;
}

static char *retrievef(va_list vlist, char c)
{
    char *result = NULL;

    switch (c)
    {
        case 's':
            result = va_arg(vlist, char *);
            break;
        case 'd':
            result = int_to_str(va_arg(vlist, int), 10);
            break;
        case 'x':
            result = int_to_str(va_arg(vlist, int), 16);
            break;
    }

    return result;
}


char *int_to_str(int integ, int basis)
{
    char *buf = malloc(BFSIZE);

    int n = 0;

    while (integ)
    {
        int next = integ % basis;

        buf[BFSIZE - 1 - n] = next < 10 ? next + '0' : 'A' + next % 10;
        n++;
        integ = integ / basis;
    }

    for (int i = 0; i < n; i++)
    {
        buf[i] = buf[BFSIZE - n + i];
    }

    buf[n] = 0;

    return buf;
}







