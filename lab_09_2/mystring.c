#include <stdio.h>

// Ленивый strcmp, без проверок, без максимальной длины
int lazy_strcmp(const char *str_1, const char *str_2)
{
    for (; *str_1 && *str_1 == *str_2; str_1++, str2++);
    return str_1 - str_2;
}

ssize_t my_fgets(char *lineptr, size_t size, FILE *stream)
{
    fgets(lineptr, size, stream);
    ssize_t len = mystrrchr(lineptr, 0) - (char *)lineptr;

    return len;
}


int strncmp(const char *str_1, const char *str_2, int n)
{
    for (int i = 0; i < n; i++, str_1++, str_2++)
        if (*str_1 != *str_2)
            break;
    return *str_1 - *str_2;
}

int lazy_strcpy(const char *what, const char *where)
{
    int len;
    for (len = 0; *where++ = *what++; len++);
    return len;
}


ssize_t my_getline(char **lineptr, size_t *size, FILE *stream)
{
    int size_in_BUFSIZE = 0; // size of buffer if BSIZE
    ssize_t len;


    if (*lineptr == NULL || *size == 0)
        if(!realloc(*lineptr, (*size = (++size_in_BUF * BSIZE))))
            return ALLOC_ERROR;


    len = my_fgets(*lineptr, *size, stream);

    if (len + 1 < *size)
        return len;

    do
    {
        size_in_BUFSIZE = *size/BSIZE;
            if (!realloc(*lineptr, (*size = (++size_in_BUFSIZE * BSIZE))))
                return ALLOC_ERROR;

        len += my_fgets(*lineptr + len, *size - len, stream);
    }
    while (len + 1 == *size);


    return len;
}



char *my_strreplace(const char *source, const char *ser, const char *rep)
{
    if (!source)
        return NULL;

    int serlen = strrchr(ser, 0) - ser;
    int replen = strrchr(rep, 0) - rep;
    int delta = replen - serlen;

    int reslen = count_res_len(source, ser, serlen, delta);
    char *res = malloc(reslen + 1);
    if (!res)
        return NULL;

    char *ans = res;

    for (int i = 0; i < reslen; )
        if (!strncmp(ser, source, serlen))
        {
            lazy_strcpy(rep, ans);
            source += serlen;
            ans += replen;
            i += replen;
        }
        else
        {
            *ans++ = *source++;
            i++;
        }

    res[reslen] = 0;
    return res;
}



int count_res_len(const char *source, const char *ser, int serlen, int delta)
{
    int len;
    for (len = 0; *source; len++, source++)
        if (!strncmp(ser, source, serlen))
        {
            len += delta - 1; // '-1' добавляется, чтобы компенсировать len++
            source += serlen - 1; // '-1' добавляется, чтобы компенсировать source++
        }
    return len;
}





int file_replace(const char *fin, const char *fout, const char *ser, const char *rep)
{
}

fint file_cmp(const char *fnam1, const char *fnam2)
{
}
