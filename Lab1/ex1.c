// Вычисление периметра треугольника

// Потапчук Артур, ИУ7-23Б

#include<stdio.h>
#include<math.h>

int main()
{
    int x1, y1; // Координаты первой точки
    int x2, y2; // Координаты второй точки
    int x3, y3; // Координаты третьей точки
    float p;    // Собственно периметр

    printf("Input coordinates of the points as in an example:\n");
    printf("<x1> <y1> <x2> <y2> <x3> <y3>\nYour input:");

    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    p = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    p += sqrt(pow(x2-x3,2) + pow(y2-y3,2));
    p += sqrt(pow(x3-x1,2) + pow(y3-y1,2));

    printf("Perimetr: %.4f", p);

    return 0;
}
