#ifndef HAPPY_END

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define N 100
#define HAPPY_END 0
#define NON_HAPPY_END -1
#define FORMAT_ERROR -2
#define OPEN_INPUT_FILE_ERROR -3
#define OPEN_OUTPUT_FILE_ERROR -4
#define INCORRECT_FILE -5
#define CLOSE_INPUT_FILE_ERROR -6
#define CLOSE_OUTPUT_FILE_ERROR -7
#define SAVE_ERROR -8
#define READING_ERROR -9
#define EMPTY_FILE -10

void format_help();
int format_prov(const int argc);
int fopen_prov(FILE **const f, const char *const filename,
                               const char *const mode);
int print_trying(FILE *const to, const int what);
int read_array(FILE *const f, int *sl, int **const el);
int major_work(int *sl, const int *const el);
int open_files(FILE **const fin, const char *const name_fone,
               FILE **const fout, const char *const name_ftwo);
int close_files(FILE *const fin, FILE *const fout);

#endif
