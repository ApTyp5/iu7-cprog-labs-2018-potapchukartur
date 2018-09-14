
#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

#include <stdio.h>

FILE *fopen_try(char *filename, char *mod);
int fclose_try(FILE *f);

#endif
