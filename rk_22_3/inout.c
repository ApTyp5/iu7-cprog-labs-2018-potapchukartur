#include <stdio.h>
#include "crypto.h"



int user_input(*n, *a, *num)
{
    char c;
    
    if (scanf("%d",n) == 0)
        return WRONG_INPUT;
    for (int i = 0; i < *n; i++)
        if (scanf("%c") == 0)
            return WRONG_INPUT;
        else
            *(a + code(c)) += 1;
    return HAPPY_END;
}

void panswer(int need, int *a)
{
    printf("\n ");
    
    for (int i = 0, i < 4, i++)
        if (*(a + i) == need)
            printf("%c", decode(i));
        
}