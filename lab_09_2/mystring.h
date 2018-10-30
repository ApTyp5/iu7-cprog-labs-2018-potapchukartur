
#ifndef __MYSTRING_H__
#define __MYSTRING_H__



int lazy_strcmp(const char *str_1, const char *str_2);
ssize_t my_fgets(char *lineptr, size_t size, FILE *stream);
int strncmp(const char *str_1, const char *str_2, int n);
int lazy_strcpy(const char *what, const char *where);
ssize_t my_getline(char **lineptr, size_t *size, FILE *stream);
char *my_strreplace(const char *source, const char *ser, const char *rep);
int count_res_len(const char *source, const char *ser, int serlen, int delta);


#endif //__MYSTRING_H__
