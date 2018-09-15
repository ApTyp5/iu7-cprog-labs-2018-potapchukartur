
#ifndef __FILEWORKS_H__
#define __FILEWORKS_H__

#include <stdio.h>

FILE *fopen_try(const char *const filename, const char *const mod);
int fclose_try(FILE *const f);

#endif
