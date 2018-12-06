
#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__


#define START_SIZE 20

int my_snprintf(char *restrict s, size_t n, const char *restrict fstr, ...);

char *int_to_str(int integ, int basis);



#endif





