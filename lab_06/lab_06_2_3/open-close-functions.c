#include "lab_06.h"



int fopen_prov(FILE **const f, const char *const filename,
                               const char *const mode)
{
    
    *f = fopen(filename, mode);
    
    if (*f)
        return HAPPY_END;

    return NON_HAPPY_END;
}

int open_files(FILE **const fin, const char *const name_fone,
               FILE **const fout, const char *const name_ftwo) 
{
    if (fopen_prov(fin, name_fone, "r"))
    {
        perror("Open input file error");
        return OPEN_INPUT_FILE_ERROR;
    }

    if (fopen_prov(fout, name_ftwo, "w"))
    {
        perror("Open output file error ");
        return OPEN_OUTPUT_FILE_ERROR;
    }
    
    return HAPPY_END;
}

int close_files(FILE *const fin, FILE *const fout)
{
    if (fclose(fin))
    {
        perror("Close input file error ");
        return CLOSE_INPUT_FILE_ERROR;
    }

    if (fclose(fout))
    {
        perror("Close output file error ");
        return CLOSE_OUTPUT_FILE_ERROR;
    }
    
    return HAPPY_END;
}