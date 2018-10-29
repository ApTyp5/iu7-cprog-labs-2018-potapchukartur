#include "define.h"
#include "debug.h"

ssize_t my_getline(char **lineptr, size_t *size, FILE *stream);

char *my_strreplace(const char *source, const char *serach, const char *replace);

int file_cmp(char *fnam1, char *fnam2);

int file_replace(str_t fin, str_t fout, str_t ser, str_t rep);


