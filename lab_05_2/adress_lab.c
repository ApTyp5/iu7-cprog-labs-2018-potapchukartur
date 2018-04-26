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

int fopen_prov(FILE **f, char *filename, char *mode)
{
    
    *f = fopen(filename, mode);
    
    if (*f)
        return HAPPY_END;
    
    return NON_HAPPY_END;
}


int read_array(FILE *f, int *sl, int *el)
{
    // sl <=> start_list
    // el <=> end_list
    int i;
    int *vspom = sl;
    
    while ((int)fscanf(f,"%d",&i) == 1)
    {   
        *vspom = i;
        vspom += 1;
    }
    el = vspom;
    if (el == sl)
    {
        if (vspom == sl)
            return EMPTY_FILE;
        
        return NON_HAPPY_END;
    }
    
    return HAPPY_END;
}


int major_work(int *sl, int *el)
{
    // sl <=> start_list
    // el <=> end_list
    // Гарантируется,  что массив между sl и el целочисленный
    
    int *vspom;
    int local_mult = 1;
    int global_sum = 0;

    for (vspom = sl; vspom != (el - 1) && *(vspom) >= 0; vspom++)
        ;
    
    for (sl = sl; sl <= vspom; sl++)
    {
        local_mult *= *sl;
        global_sum += local_mult;
    }

    return global_sum;
}


int main(int argc, char **argv)
{
    int a[N] = {0};
    FILE *fin = NULL, *fout = NULL;
    int *start_list = a;
    int *end_list = NULL;
    int rc = HAPPY_END;
    int sum;
    

    
    if (argc != 3)
    {
        format_help();
        return FORMAT_ERROR;
    }
    
    if (fopen_prov(&fin, *(argv + 1), "r"))
    {
        perror("Open input file error");
        return OPEN_INPUT_FILE_ERROR;
    }

    if (fopen_prov(&fout, *(argv + 2), "w"))
    {
        perror("Open output file error ");
        rc = OPEN_OUTPUT_FILE_ERROR;
    }

    vs = read_array(fin, start_list, end_list);
    
    case (vs)     
    
    

    sum = major_work(start_list, end_list);

    printf("\n%d\n",sum);
    
    if (!fprintf(fout,"%d",sum) && !rc)
    {
        perror("Print error: ");
        rc = SAVE_ERROR;
    }
    
    if (fclose(fin) && !rc)
    {
        perror("Close input file error ");
        rc = CLOSE_INPUT_FILE_ERROR;
    }

    if (fclose(fout) && !rc)
    {
        perror("Close output file error ");
        rc = CLOSE_OUTPUT_FILE_ERROR;
    }
    
    return rc;
}
