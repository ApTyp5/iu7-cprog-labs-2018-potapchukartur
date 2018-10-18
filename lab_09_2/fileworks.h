
#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__


#include "define.h"

int fopen_try(file_t *f, str_t fname, str_t mod);
int file_replace(str_t fname1, str_t fname2,
    str_t serach, str_t replace);

#endif

            



