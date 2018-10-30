



#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

#include <stdio.h>

FILE *fopen_try(char *filename, char *mod, int *rc);

int file_cmp(const char *fnam1, const char *fnam2);

int file_replace(const char *fin, const char *fout, const char *ser, const char *rep);

#endif
