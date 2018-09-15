#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fileworks.h"
#include "define.h"



FILE *fopen_try(const char *const filename, const char *const mod)
{
    FILE *f = NULL;
    f = fopen(filename, mod);

#ifdef    NDEBUG
    if (!f)
        fprintf(stderr, "Can't open %s: %s\n", filename, strerror(errno));
#endif

    return f;
}


int fclose_try(FILE *const f)
{
    if (fclose(f))
    {
#ifdef    NDEBUG
        perror("Can't close file");
#endif
        return NON_HAPPY_END;
    }

    return HAPPY_END;
}


