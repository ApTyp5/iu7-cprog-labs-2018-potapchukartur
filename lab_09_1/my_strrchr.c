#include <stdio.h>

char *my_strrchr(const char *s, int c)
{
    const char *start = s;

    if (!s)
        return NULL;

    // After cycle *s == 0
    for (; *s; s++);
    
    for (; s != start; s--)
        if (*s == c)
            return (char *)s;

    if (*start == c)
        return (char *)start;


    return NULL;
}

   



