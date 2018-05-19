#include <stdio.h>
#include "crypto.h"



int main()
{
    int n, kvo[4] = {0};
    int number; // Номер частоты 
    int s_s[4] = {0};// Множество всех значений kvo
    
    user_input(&n, kvo, &number);
    
    fill_sing_sort(s_s, kvo);
    
    int need_kvo = s_s[number];
    
    panswer(need_kvo, kvo);
    
    return HAPPY_END;
}
