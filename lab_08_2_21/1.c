#include <stdio.h>

int main()
{
    FILE *f = fopen("1.txt", "w");
    fclose(f);
    return 0;
}

