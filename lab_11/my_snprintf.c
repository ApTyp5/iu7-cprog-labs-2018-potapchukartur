
int my_snprintf(char *restrict s, size_t n, const char *restrict fstr, ...)
{
    int count = 0;

    if (!s || !n)
        return count;


    while (n && fstr)
    {
        if (*fstr == '%')
        {
            fstr++;

            char c = fstr;
            switch (c)
            {
            }
        }
        else
        {
            *s++ = *fstr++;
        }

        n--;
    }

    return count;
}


int my_strncpy(char *what, char *where, int *n_where)
{
}


