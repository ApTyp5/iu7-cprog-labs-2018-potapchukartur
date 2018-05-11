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
int open_files(FILE **const fone, const char *const name_fone,
               FILE **const ftwo, const char *const name_ftwo);
int close_files(FILE *const fone, FILE *const ftwo);




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