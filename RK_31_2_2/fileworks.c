#include <stdio.h>
#include "fileworks.h"
#include "define.h"




FILE *fopen_try(char *fnam, char *mod, int *rc)
{
    FILE *f = fopen(fnam, mod);

    if (f == NULL)
        *rc = FOPEN_ERROR;

    return f;
}



