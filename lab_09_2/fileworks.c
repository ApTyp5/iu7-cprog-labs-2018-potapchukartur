
#include <stdio.h>
#include "define.h"
#include "aplog.h"


int fopen_try(file_t *f, str_t fname, str_t mod)
{
    f = fopen(fname, mod);
    if (!f)
        return FOPEN_ERROR;

    return HAPPY_END;
}


int file_replace(str_t fname1, str_t fname2,
    str_t serach, str_t replace)
{
    file_t in = NULL, out = NULL;
    str_t lineptr;
    int len = 0;


    int rc = fopen_try(&in, fname1, "r");
    if (!rc)
        rc = fopen_try(&in, fname2, "w");


    if (!rc)
        while (my_getline(lineptr, &len, in) > 0)
            



