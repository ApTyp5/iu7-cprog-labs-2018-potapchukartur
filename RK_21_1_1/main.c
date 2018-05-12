/*Получить новое число составленное из четных(нечетных) цифр исходного числа. Пример: 12345 -> 24(135)*/
// Вариант 1, номер в журнале 17
// Потапчук Артур

#include <stdio.h>
#include <math.h>
#define HAPPY_END 0
#define WRONG_INPUT -1


int prov_input(unsigned int *w)
{
    if (scanf("%u",w) || *w > 0)
        return HAPPY_END;
    return WRONG_INPUT;


}


int main()
    // w - Ввод
    unsigned int w;
    int vspom = 0;
    unsigned int viv_1 = 0, viv_2 = 0;
    short int kvo_raz = 0;

    printf("Input a natural number: ");
    if (prov_input(&w))
    {
        printf("Wrong input!");
        return WRONG_INPUT;
    }

    while (w>0)
    {
        if (kvo_raz%2)
    {
        viv_2 = viv_2 + pow(10, kvo_raz/2)*(w%10);
        printf("%u viv_2: %u\n",kvo_raz,viv_2);
    }
    else
    {
        
        viv_1 = viv_1 + pow(10,kvo_raz/2)*(w%10);
        printf("%u viv_1: %u\n",kvo_raz,viv_1);
    }
    w = w/10;
    printf("%u",w);
    kvo_raz += 1;
    vspom += 1;

    }
    printf("%u %u\n", viv_1,viv_2);
    if (kvo_raz%2)
    {
        printf("%u(%u)",viv_2,viv_1);
        return HAPPY_END;
    }
    else
    {
        printf("%u(%u)",viv_1,viv_2);
        return HAPPY_END;
    }
}



