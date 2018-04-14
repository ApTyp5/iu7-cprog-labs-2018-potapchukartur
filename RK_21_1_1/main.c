/*Получить новое число составленное из четных(нечетных) цифр исходного числа. Пример: 12345 -> 24(135)*/
// Вариант 1, номер в журнале 17
// Потапчук Артур

#include <stdio.h>
#define HAPPY_END 0
#define WRONG_INPUT -1


int prov_input(unsigned int *w)
{
    if (scanf("%ui"))
	return HAPPY_END;
    return WRONG_INPUT;


int main()
{
    // w - Ввод
    unsigned int w;
    unsigned int vspom;
    unsigned int viv_1 = 0, viv_2 = 0;
    short int kvo_raz = 0;

    printf("Input a natural number: ");
    if (prov(&w))
    {
	printf("Wrong input!");
	return WRONG_INPUT;
    }

    while (w>0)
    {
	if (kvo_raz/2)
	    viv_2 = pow(10,kvo_raz)*viv_2 + w%10;
	else
	    viv_1 = pow(10,kvo_raz)*viv_1 + w%10;
	w = w/10;
	kvo_raz++;
    }
    if (kvo_raz/2)
    {
	printf("%ui(%ui)",viv_2,viv_1);
	return HAPPY_END;
    }
    else
    {
        printf("%ui(%ui)",viv_1,viv_2);
	return HAPPY_END;
    {
}



