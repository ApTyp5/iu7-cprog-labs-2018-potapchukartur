

#ifndef __MYSTRING_H__
#define __MYSTRING_H__



#include <stdlib.h>
#include "define.h"

ssize_t my_getline(char **lineptr, size_t *n, file_t stream);
char *str_replace(const char *source, const char *serach, const char *replace);
void fs_printf(file_t f, char *str);
int count_len(const char *source, const char * serach, int slen, int rlen, int delta);
int my_strcpy(const char * what, char * where);
int my_strlen(const char *str);
int my_strsize(const char *str);
int my_strcmp(const char *str1, const char *str2);
int my_memcmp(const void *ptr1, const void *ptr2, const int len);
void my_memcpy(const void *what, void *where, const int len);


#endif


