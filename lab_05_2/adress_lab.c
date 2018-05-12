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

FILE *fopen_try(const char *const filename, const char *const mode)
{
    FILE *f = fopen(filename, mode);
    if (!f)
        perror("Open file error");
    
    return f;
}

int print_trying(FILE *const to, const int what)
{
    if (!fprintf(to,"%d",what))
        return SAVE_ERROR;
    
    return HAPPY_END;
}

FILE *read_array(FILE *const f, int *sl)
{
    // sl <=> start_list
    // el <=> end_list
    int i;
    
    while ((int)fscanf(f,"%d",&i) == 1)
    {   
        *sl = i;
        sl += 1;
        flag = 0;
    }
    
    return sl;
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
    
    if (!(fin = fopen_try(*(argv + 1), "r")))
        return OPEN_INPUT_FILE_ERROR;
    
    if (!(fout = fopen_try(*(argv + 2), "w")))
    {
        fclose(fin);
        return OPEN_OUTPUT_FILE_ERROR;
    }
    
    if (!rc)
    {
        end_list = read_array(fin, start_list);
        rc = (end_list == empty_file)? EMPTY_FILE : HAPPY_END; 
        if (!rc)
        {
            sum = major_work(start_list, end_list);
            rc = print_trying(fout, sum);
            if (!rc)
                rc = close_files(fin, fout);
        }
        else
            close_files(fin, fout);
    }
    else
        close_files(fin, fout);

    return rc;
}
