
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char *str = malloc(13);
    size_t n = -12;
    FILE *f = stdin;

    fprintf(stdout, "len = %ld\n", getdelim(&str, &n, '\n', f));
    printf("n = %ld\n", n);

   

    return 0;
}

    
