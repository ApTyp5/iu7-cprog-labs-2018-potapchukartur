#define        HAPPY_END    0
#define        NON_HAPPY_END    -2
#define        N        4
#define        ARR        "AGTH"

#ifndef __INOUT_H__
#define __INOUT_H__

int user_input(const char *const filename, int *const kvo, int *const num);
void ending(FILE *f);
int fclose_try(FILE *f);
FILE *fopen_try(const char *const filename, const char *const mod);

#endif
