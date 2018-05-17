#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "open_close_file.h"




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