#include "lab_06.h"




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