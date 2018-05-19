#include <stdio.h>
#include "crypto.h"
#include "inout.h"



int user_input(int *n, int *a, int *num)
{
    char c;
    
    if (scanf("%d",n) == 0)
        return WRONG_INPUT;
	 
    for (int i = 0; i < *n; i++)
        if (scanf("%c", &c) == 0)
            return WRONG_INPUT;
        else
            *(a + code(c)) += 1;
	
	if (scanf("%d",n) == 0)
        return WRONG_INPUT;
	
    return HAPPY_END;
}

void panswer(int need, int *a)
{
    printf("\n ");
    
    for (int i = 0; i < 4; i++)
        if (*(a + i) == need)
            printf("%c", decode(i));
        
}