

#ifndef READ_WRITE
#define READ_WRITE

#include <stdio.h>
int print_trying(FILE *const to, const int what);
int read_array(FILE *const f, int *sl, int **const el);

#endif

#ifndef N
#define N 10
#endif

#ifndef HAPPY_END
#define HAPPY_END 0
#endif

#ifndef EMPTY_FILE
#define EMPTY_FILE -10
#endif

#ifndef SAVE_ERROR
#define SAVE_ERROR -8
#endif
