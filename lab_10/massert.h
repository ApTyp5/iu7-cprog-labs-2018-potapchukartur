
#ifndef __MASSERT_H__
#define __MASSERT_H__

#include <stdio.h>

#define massert(expression)                         \
fprintf(stderr, "%s:%4d --> massertion '"    \
#expression "' %s\n", __FILE__, __LINE__, \
(expression) == 0 ? "failed" : "completed");


#endif  // __MASSERT_H__
