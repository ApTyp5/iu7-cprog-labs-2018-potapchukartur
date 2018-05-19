

#ifndef OPEN_CLOSE
#define OPEN_CLOSE

int fopen_prov(FILE **const f, const char *const filename,
                               const char *const mode);
int open_files(FILE **const fone, const char *const name_fone,
               FILE **const ftwo, const char *const name_ftwo);
int close_files(FILE *const fone, FILE *const ftwo);

#endif

#ifndef HAPPY_END
#define HAPPY_END 0
#endif

#ifndef NON_HAPPY_END
#define NON_HAPPY_END -1
#endif

#ifndef OPEN_INPUT_FILE_ERROR
#define OPEN_INPUT_FILE_ERROR -3
#endif

#ifndef OPEN_OUTPUT_FILE_ERROR
#define OPEN_OUTPUT_FILE_ERROR -4
#endif

#ifndef CLOSE_INPUT_FILE_ERROR
#define CLOSE_INPUT_FILE_ERROR -6
#endif

#ifndef CLOSE_OUTPUT_FILE_ERROR
#define CLOSE_OUTPUT_FILE_ERROR -7
#endif