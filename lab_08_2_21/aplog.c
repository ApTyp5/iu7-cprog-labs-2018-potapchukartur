#include <stdio.h>

FILE *_apl;
int indent = 1;

#include "aplog.h"



void start_log(const char *lname, const char *begin_fname,
    const char *begin_func, int line)
{
    _apl = fopen(lname, "a");
    setvbuf(_apl, (char *)NULL, _IONBF, 0);

    fprintf(_apl, "\n\n");
    fprintf(_apl, "Log started in file '%s'\n", begin_fname);
    fprintf(_apl, "%4d",line);
    pindent("----");
    fprintf(_apl, "> %s:\t%20s\n", begin_func, begin_fname);

    indent++;
}


void log_in(int line, const char *func, const char *fname)
{
    fprintf(_apl, "%4d", line);
    pindent("----");
    fprintf(_apl, "> %s\t%20s\n", func, fname);
    
    indent++;
}

void val_pindent(char *ind)
{
    fprintf(_apl, "       ");
    pindent(ind);
}
    
void pindent(char *ind)
{
    for (int i = 0; i < indent; i++)
        fprintf(_apl, "%s", ind);
}





