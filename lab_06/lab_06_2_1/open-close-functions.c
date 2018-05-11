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



int fopen_prov(FILE **const f, const char *const filename,
                               const char *const mode)
{
    
    *f = fopen(filename, mode);
    
    if (*f)
        return HAPPY_END;
    perror("Open file error");
    return NON_HAPPY_END;
}

int open_files(FILE **const fone, const char *const name_fone,
               FILE **const ftwo, const char *const name_ftwo) 
{
    if (fopen_prov(fone, name_fone, "r"))
    {
        perror("Open input file error");
        return OPEN_INPUT_FILE_ERROR;
    }

    if (fopen_prov(ftwo, name_ftwo, "w"))
    {
        perror("Open output file error ");
        return OPEN_OUTPUT_FILE_ERROR;
    }
    
    return HAPPY_END;
}

int close_files(FILE *const fone, FILE *const ftwo)
{
    if (fclose(fone))
    {
        perror("Close input file error ");
        return CLOSE_INPUT_FILE_ERROR;
    }

    if (fclose(ftwo))
    {
        perror("Close output file error ");
        return CLOSE_OUTPUT_FILE_ERROR;
    }
    
    return HAPPY_END;
}