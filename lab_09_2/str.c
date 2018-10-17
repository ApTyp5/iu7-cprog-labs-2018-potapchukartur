
#include "define.h"

// null-terminated and includes the n/l character
ssize_t my_getline(str_t *lineptr, size_t *n, file_t f)
{
    int delim = '\n';

    if (*lineptr == NULL || *n == 0)
    {
        // should be freed even the 'my_getline' will fail
        *lineprt = malloc(BUFSIZE);
        *n = BUFSIZE;
    }

    if (!f)
        return ERROR;

    while
    char buf[BUFFSIZE];
    *n = BUFFSIZE;

    while (fgets(buf, BUFSIZE, f))
    {
        if (*n < 



    

}


