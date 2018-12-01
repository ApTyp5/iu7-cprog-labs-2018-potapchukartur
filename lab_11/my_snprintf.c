
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

            char c = *fstr;
            switch (c)
            {
                case 's':
                    while (

                    break;

                case 'i':

                    break;
                    
                case 'x':

                    break;

                default:
                    return count;
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



