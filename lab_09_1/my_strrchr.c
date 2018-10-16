
#include <stdio.h>


char *endstr(const char *s);


// Ищет первое вхождение символа c в s
char *my_strrchr(const char *s, int c)
{
    for (char *end = endstr(s); s != end; end--)
        if (*end == c)
            return end;

    return NULL;
}

// Возвращает указатель на '\0' строки s
char *endstr(const char *s)
{
    for (; *s++;);
    return (char *)s - 1;
}

