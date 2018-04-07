/* Программа, считающая общее сопротивление
трёх паралельно соединеных резисторов*/

// Потапчук Артур, ИУ7-23Б


#include<stdio.h>

int main()
{
    float R1, R2, R3; // "Resistance" (сопротивление резисторов)
    float chainr;     // "Chain resistance" (Сопротивление всей цепи)

    printf("Input resistances as in example:\n");
    printf("<R1> <R2> <R3>\n");

    scanf("%f %f %f", &R1, &R2, &R3);

    R1 = 1.0/R1;
    R2 = 1.0/R2;
    R3 = 1.0/R3;


    chainr = 1.0/(R1 + R2 + R3);
    printf("The chain resistance: %.4f", chainr);

    scanf("%f", &R1);

    return 0;
}
