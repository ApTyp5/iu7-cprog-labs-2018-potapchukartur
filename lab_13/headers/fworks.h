#ifndef __FWORKS_H__
#define __FWORKS_H__

#include <stdio.h>

int fopen_try(FILE **f, char *fnam, char *mod)
{
    *f = fopen(fnam, mod);
    if (*f)
        return HAPPY_END;

    return FOPEN_ERROR;
}


#endif
