
#ifndef __MASSERT_H__
#define __MASSERT_H__

#include <stdio.h>

#define massert(expression)                     \
fprintf(stderr, "%30s:%4d --> %-40s --> %9s\n",       \
__func__, __LINE__, #expression,                \
(expression) == 0 ? "failed" : "completed");



#endif  // __MASSERT_H__
