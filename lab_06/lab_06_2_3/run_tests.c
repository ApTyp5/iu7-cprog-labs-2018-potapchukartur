#include <stdio.h>
#include "tests.h"

#define HAPPY_END 0

int main()
{
    FILE *f = fopen("test.results","w");

    format_tests(f);
    major_work_tests(f);
    open_close_tests(f);
    read_write_tests(f);

    fclose(f);

    return HAPPY_END;
}