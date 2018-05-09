/* Сумма последовательных произведений элементов массива
до первого отрицательного(включительно) или до конца */

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

void format_help()
{
    printf("Wrong call format!\n");
    printf("Right format call of the function:\n");
    printf("main <source filename> <target filename>\n");
}

int format_prov(const int argc)
{
    if (argc != 3)
    {
        format_help();
        return FORMAT_ERROR;
    }
    
    return HAPPY_END;
}

int fopen_prov(FILE **const f, const char *const filename,
                               const char *const mode)
{
    
    *f = fopen(filename, mode);
    
    if (*f)
        return HAPPY_END;
    perror("Open file error");
    return NON_HAPPY_END;
}

int print_trying(FILE *const to, const int what)
{
    if (!fprintf(to,"%d",what))
        return SAVE_ERROR;
    
    return HAPPY_END;
}

int read_array(FILE *const f, int *sl, int **const el)
{
    // sl <=> start_list
    // el <=> end_list
    int i;
    _Bool flag = 1;
    
    while ((int)fscanf(f,"%d",&i) == 1)
    {   
        *sl = i;
        sl += 1;
        flag = 0;
    }
    
    *el = sl;
    
    if (flag)
    {
        fprintf(stderr,"The input file msut contain integers.\n");
        return EMPTY_FILE;
    }
    
    return HAPPY_END;
}


int major_work(int *sl, const int *const el)
{
    // sl <=> start_list
    // el <=> end_list
    // Гарантируется,  что массив между sl и el целочисленный
    
    int *vspom;
    int local_mult = 1;
    int global_sum = 0;

    for (vspom = sl; vspom != (el - 1) && *(vspom) >= 0; vspom++)
        ;
    
    for (; sl <= vspom; sl++)
    {
        local_mult *= *sl;
        global_sum += local_mult;
    }

    return global_sum;
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

int main(int argc, char **argv)
{
    int a[N] = {0};
    FILE *fin = NULL, *fout = NULL;
    int *start_list = a;
    int *end_list = NULL;
    int rc = HAPPY_END;
    int sum;

    if (format_prov(argc) == FORMAT_ERROR)
        return FORMAT_ERROR;
    
    rc = open_files(&fin,*(argv + 1), &fout, *(argv + 2));
    
    if (!rc)
    {
        rc = read_array(fin, start_list, &end_list);
        if (!rc)
        {
            sum = major_work(start_list, end_list);
            rc = print_trying(fout, sum);
            if (!rc)
                rc = close_files(fin, fout);
        }
        else
            close_files(fin,fout);
    }
    else
        close_files(fin, fout);

    return rc;
}
