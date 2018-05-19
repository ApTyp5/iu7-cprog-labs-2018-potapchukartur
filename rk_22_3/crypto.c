#include "crypto.h" 


int str_equiv(char a, char b)
{
    if ((int)a == (int)b)
        return HAPPY_END;
	
    return NON_HAPPY_END;
}


// A C T G -> 0 1 2 3
int code(char c)
{
    if (str_equiv(c, 'A'))
        return 0;
    else if (str_equiv(c, 'C'))
        return 1;
    else if (str_equiv(c, 'T'))
        return 2;
    else if (str_equiv(c, 'G'))
        return 3;
	else
		return NON_HAPPY_END;
}

char decode(int n)
{
    if (n == 0)
        return 'A';
    else if (n == 1)
        return 'C';
    else if (n == 2)
        return 'T';
    else if (n == 3)
        return 'G';
	else
		return NON_HAPPY_END;
}