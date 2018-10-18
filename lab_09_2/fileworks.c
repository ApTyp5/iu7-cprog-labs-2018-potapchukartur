
#include <stdio.h>
#include "define.h"
#include "aplog.h"
#include "mystring.h"


int fopen_try(file_t *f, str_t fname, str_t mod)
{
    WELC;

    *f = fopen(fname, mod);
    if (!f)
        return FOPEN_ERROR;

    return HAPPY_END;
}


int file_replace(str_t fname1, str_t fname2,
    str_t serach, str_t replace)
{
    WELC;

    file_t in = NULL;
    file_t out = NULL;
    str_t lineptr = NULL;
    str_t replaced_str = NULL;
    size_t size = 0;




    int rc = fopen_try(&in, fname1, "r");
    if (!rc)
        rc = fopen_try(&out, fname2, "w");


    if (!rc)
    {
        while (my_getline(&lineptr, &size, in) > 0)
        {
            replaced_str = str_replace(lineptr, serach, replace);
            if (!replaced_str)
            {
                rc = ALLOCATION_ERROR;
                break;
            }

            fs_printf(out, replaced_str);
        fprintf(out, "%c", EOF);
        }
    }

    free(replaced_str);
    free(lineptr);

    if (!rc)
        rc = fclose(in);
    if (!rc)
        rc = fclose(out);

    return rc;
}





            



