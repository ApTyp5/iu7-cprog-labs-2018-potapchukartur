//Программа, переводящая секунды в часы + минуты + секунды

// Потапчук Артур, ИУ7-23Б

/*
    num	Вводимое число секунд
    hours	Выводимое число часов
    minutes	Выводимое число минут
    seconds	Выводимое число секунд
*/

#include <stdio.h>
#define HOURS	3600
#define MINUTES	60

int main(void)
{
    int num;
    int hours;
    int minutes;
    int seconds;

    printf("Input the number of seconds:");
    scanf("%d", &num);

    hours = num / HOURS;
    num = num % HOURS;

    minutes = num / MINUTES;
    num = num % MINUTES;

    seconds = num;

    printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    scanf("%d",&num);
}
