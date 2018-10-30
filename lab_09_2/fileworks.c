#include <stdio.h>
#include "define.h"
#include "mystring.h"
#include "debug.h"


FILE *fopen_try(const char *filename, const char *mod, int *rc)
{
	FILE *f = NULL;
	f = fopen(filename, mod);
	if (!f)
        *rc = FOPEN_ERROR;

	return f;
}

int file_replace(const char *fin_nam, const char *fout_nam, const char *ser, const char *rep)
{
    int rc = HAPPY_END;
    char *buff_in = NULL;
    char *buff_out = NULL;
    size_t size_in = 0;
    ssize_t len_in = 0;


    FILE *fin = fopen_try(fin_nam, "r", &rc);
    FILE *fout;
    if (!rc)
        fout = fopen_try(fout_nam, "w", &rc);

    if (!rc)
        while ((len_in = my_getline(&buff_in, &size_in, fin) > 0) && !feof(fin))
        {
            buff_out = my_strreplace(buff_in, ser, rep);
            if (!buff_out)
                return ALLOC_ERROR;

            fprintf(fout, "%s", buff_out);
        }

    fclose(fin);
    fclose(fout);

    return HAPPY_END;
}


int file_cmp(const char *fnam1, const char *fnam2)
{
    int rc = HAPPY_END;

    char *line1 = NULL;
    size_t size1;
    char *line2 = NULL;
    size_t size2;
    FILE *f1 = fopen_try(fnam1, "r", &rc);
    FILE *f2 = fopen_try(fnam2, "r", &rc);


    if (!rc)
        while (1)
        {
            my_getline(&line1, &size1, f1);
            my_getline(&line2, &size2, f2);

            if (feof(f1) && feof(f2))
                break;
            if (!feof(f1) && feof(f2))
                return 1;
            if (feof(f1) && !feof(f2))
                return -1;

            rc = lazy_strcmp(line1, line2);
            if (rc)
                break;
        }

    fclose(f1);
    fclose(f2);

    return rc;
}






