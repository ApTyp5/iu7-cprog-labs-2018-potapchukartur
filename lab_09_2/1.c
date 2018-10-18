
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int my_strlen(char *str)
{
    int size = 0;
    for (; *str++; size++);
    return size;
}

int main(int ac, char *av[])
{
    char *lptr = NULL;
    size_t size = 0;
    FILE *f = tmpfile();

    fprintf(f, "%c", '\0');
    rewind(f);
    printf("size = %ld\n len = %ld\n", getline(&lptr, &size, f), size);
/*
    printf("ac = %d\n", ac);
    printf("len av[1] = %d\n", strlen(av[1]));
    printf("mylen av[1] = %d\n", my_strlen(av[1]));
    printf("av[1][4] = %d\n", av[1][4]);


    */
    return 0;
}

