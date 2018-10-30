#include "define.h"
#include "debug.h"
#include "mystring.h"


int format_check(int ac, char **av)
{
    if (ac != 7 ||
        !((lazy_strcmp(av[3], "-s") == EQ && lazy_strcmp(av[5], "-r") == EQ) ||
        (lazy_strcmp(av[3], "-r") == EQ && lazy_strcmp(av[5], "-s") == EQ))) 

        return FORMAT_ERROR;
        
    return HAPPY_END;
}

void show_prompt(int rc)
{
    printf("rc = %d\n", rc);
}

void prepare_args(char *av[], str_t *fin, str_t *fout, str_t *ser, str_t *rep)
{
    *fin = av[1];
    *fout = av[2];

    if (!lazy_strcmp(av[3], "-s"))
    {
        *ser = av[4];
        *rep = av[6];
    }
    else
    {
        *rep = av[4];
        *ser = av[6];
    }
}
