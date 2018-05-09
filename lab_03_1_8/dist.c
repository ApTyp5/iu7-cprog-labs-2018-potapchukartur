#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define HAPPY_END 0
#define NON_HAPPY_END -2
#define EMPTY_OR_INCORRECT_FILE -3
#define NO_LOCAL_MAXIMUMS -4


void format_help()
{
    printf("Format of input:\n");
    printf("dist_between_lock_max <input file> <output file>\n");
}

int fopen_check(FILE **f, char *filename, char *mode)
{
    if ((*f = fopen(filename, mode)) == 0)
    {
        fprintf(stderr, "Error while opening '%s' : %s", filename, 
        strerror(errno));
        return NON_HAPPY_END;
    }
    
    return HAPPY_END;
}

int fclose_check(FILE *f, char *filename)
{
    if (fclose(f))
    {
        fprintf(stderr, "Error while closing '%s': %s", filename,
        strerror(errno));
        return NON_HAPPY_END;
    }
    
    return HAPPY_END;
}

void move(int *e1, int *e2, int *e3)
{
    *e1 = *e2;
    *e2 = *e3;
}

int dist_between_lock_max(FILE *f)
{
    // Соотвественно 1-ый, 2-ой, 3-ий элемент последовательности
    int e1, e2, e3;
    // Номер локального максимума
    int nmax = -1;
    // Счётчик
    int schet = 2;
    // Наименьшее расстояние (дистанция)между локальными максимумами
    int dist = INT_MAX;
    // Вспомогательная переменная, обозначает расстояние, сравниваемое
    // с текущим dist
    int vspom;
    
    if (fscanf(f,"%d%d", &e1, &e2) == 2)
    {
        if (e1 > e2)
            nmax = 1;
        else
            while (fscanf(f,"%d",&e3) == 1)
            {
                if (e1 < e2 && e2 > e3)
                {
                    nmax = schet;
                    schet++;
                    move(&e1, &e2, &e3);
                    break;
                }
                move(&e1, &e2, &e3);
                schet++;
            }
            
        if (nmax > 0)
        {
            while (fscanf(f,"%d",&e3) == 1)
            {
                if (e1 < e2 && e2 > e3)
                {
                    dist = (vspom = schet - nmax) < dist ? vspom : dist;
                    nmax = schet;
                }
                schet++;
                move(&e1,&e2,&e3);
            }
            
            if ((e2 > e1) && ((vspom = schet - nmax) < dist))
                dist = vspom;
            
            return dist;
        }
        else
            return NO_LOCAL_MAXIMUMS;
    }
    else
        return EMPTY_OR_INCORRECT_FILE;
}

void try_to_printf(FILE *f, int *rc)
{
    switch (*rc)
    {
        case EMPTY_OR_INCORRECT_FILE:
            fprintf(stderr,"Empty or incorrect file was given.\n");
            break;
        case NO_LOCAL_MAXIMUMS:
            fprintf(stderr,"There are no local maximums in file.\n");
            break;
        default:
            if (fprintf(f, "%d", *rc) != 1)
                perror("Error while writing into output file");
            else
                *rc = HAPPY_END;
    }        
}

int main(int argc, char **argv)
{
    FILE *fb , *fe ;
    int rc;
    
    rc = (argc == 3) ? HAPPY_END : NON_HAPPY_END;

    if (rc)
        format_help();
    
    if (!rc)
        rc = fopen_check(&fb, argv[1], "r");
    
    if (!rc)
        rc = fopen_check(&fe, argv[2], "w");
    
    if (!rc)
        rc = dist_between_lock_max(fb);
    
    try_to_printf(fe,&rc);
    
    if (!rc)
        rc = fclose_check(fb, argv[1]);
    else
        fclose(fb);
    
    if (!rc)
        rc = fclose_check(fe, argv[2]);
    else
        fclose(fe);
    
    return rc;
}