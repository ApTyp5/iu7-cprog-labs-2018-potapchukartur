#include <errno.h>
#include <stdio.h>
#include "help.h"
#include "coding.h"
#include "inout.h"
#include <string.h>

#define        HAPPY_END    0
#define        NON_HAPPY_END    -2
#define        N        4
#define        ARR        "AGTH"

int user_input(const char *const filename, int *const kvo, int *const num)
{
    char c;
         FILE *f = fopen_try(filename, "r");
           
    if (!f)
        return NON_HAPPY_END;

    for (;;)
    {
        if (fscanf(f, "%c", &c))
        {
            if (c == ' ')
                continue;
            
            if (in(c, ARR, N) == 0)
                kvo[coding(c)] += 1;
            
            
            else if (c <= '9' && c >= '0')
            {
                *num = (int)c - (int)'0';
                break;
            }
            
            else
            {
                ending(f);
                return NON_HAPPY_END;
            }    
        }
        else
        {
            ending(f);        
            return     NON_HAPPY_END;
        }    
    }

    if (fclose_try(f))
        return NON_HAPPY_END;

    return HAPPY_END;
<<<<<<< HEAD
}


int panswer(const char *const filename, const int num, const int *const sort, const int* const kvo)
{
    FILE *f = fopen_try(filename, "w");
    if (!f)
        return NON_HAPPY_END;

    for (int i = 0; i < N; i++)
        if (*(kvo + i) == *(sort + num))
            fprintf(f, "%c ", encoding(i));

    fprintf(f, "\n");
    
    if (fclose_try(f))
        return NON_HAPPY_END;

    return HAPPY_END;
=======
>>>>>>> 1dd6cbb231534f9d042daf35211596613ccdfbd2
}




void ending(FILE *f)
{
    fclose(f);
    fprintf(stderr, "Wrong intput! The input must ");
    fprintf(stderr, "contain a 'A' 'G' 'T' 'H' ");
    fprintf(stderr, " massive and a number in the end\n");
}


int fclose_try(FILE *f)
{
    int rc = fclose(f);

    if (rc)
        perror("Can't close file");

    return rc;
}


FILE *fopen_try(const char *const filename, const char *const mod)
{
    FILE *f = NULL;
<<<<<<< HEAD
    f = fopen(filename, mod);
=======
    f = fopen(filename, "r");
>>>>>>> 1dd6cbb231534f9d042daf35211596613ccdfbd2

    if (!f)
        fprintf(stderr, "Can't open the %s file: %s\n", filename, strerror(errno));

    return f;
    
}
