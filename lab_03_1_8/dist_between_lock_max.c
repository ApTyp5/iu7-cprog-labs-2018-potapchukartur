﻿/* Программа записывает в выходной файл наименьшее расстояние 
между локальными максимами последовательности, расположенной
во входном файле*/

// Потапчук Артур, ИУ7-23Б


#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#define INPUT_ERROR -1
#define NOT_CORRECT_SEQUENCE -2
#define INCORRECT_CALL_OF_FUNCTION -3
#define OUTPUT_FILE_OPEN_ERROR -4
#define INPUT_FILE_OPEN_ERROR -5

// Вывод шаблона команды
void help()
{
    printf("Format of input:\n");
    printf("dist_between_lock_max <input file> <output file>\n");
}

// Циклический сдвиг элемангов на 1 назад(1-ый "забывается")
void cycle(int *e1, int *e2, int *e3)
{
    *e1 = *e2;
    *e2 = *e3;
}

// Минимальная дистанция между локальными максимумами
int dist_beetween_lock_max(FILE *fb, FILE *fe)
{
    // Соотвественно 1-ый, 2-ой, 3-ий элемент последовательности
    int e1, e2, e3;
    // Номер локального максимума
    int nmax = -1;
    // Счётчик
    int schet = 2;
    // Наименьшее расстояние (дистанция)между локальными максимумами
    int dist = INT_MAX;
    // Вспомогательная переменная
    int vspom;


    if (fscanf(fb,"%d%d",&e1,&e2) == 2)
    {
        if (e1 > e2)
            nmax = 1;
        else
            while (fscanf(fb,"%d",&e3) == 1)
            {
                if (e1 < e2 && e2 > e3)
                {
                    nmax = schet;
                    schet++;
                    cycle(&e1, &e2, &e3);
                    break;
                }
                cycle(&e1, &e2, &e3);
                schet++;
            }

        if (nmax > 0)
        {
            while (fscanf(fb,"%d",&e3) == 1)
            {
                if (e1 < e2 && e2 > e3)
                {
                    dist = (vspom = schet - nmax) < dist ? vspom : dist;
                    nmax = schet;
                }
                schet++;
                cycle(&e1,&e2,&e3);

            }
            if ((e2 > e1) && ((vspom = schet - nmax) < dist))
                dist = vspom;
            if (dist != INT_MAX)
            {
                fprintf(fe, "%d\n",dist);
                return 0;
            }
            else
            {
                printf("Input sequence must have two local maximums!");
                return NOT_CORRECT_SEQUENCE;
            }
        }
        else
        {
            printf("Input sequence must have two local maximums!");
            return NOT_CORRECT_SEQUENCE;
        }
    }
    else
    {
        printf(("Wrong input!"));
        return INPUT_ERROR;
    }

}

int main(int args, char** argv)
{
    // "return counter"
    int rc;
    // "file begin", "file end"
    FILE *fb, *fe;

    if (3 != args)
    {
        rc = INCORRECT_CALL_OF_FUNCTION;
        help();
    }
    else
    {
        fb = fopen(argv[1],"r");
        if (fb)
        {
            fe = fopen(argv[2],"w");

            if (fe)

            {
                rc = dist_beetween_lock_max(fb, fe);
            }

            else

            {
                rc = OUTPUT_FILE_OPEN_ERROR;
                fprintf(stderr,"Can't open file %s: %s",argv[2],
                        strerror(errno));
            }

            fclose(fe);
        }
        else
        {
            rc = INPUT_FILE_OPEN_ERROR;
            fprintf(stderr, "Can't open file %s: %s",argv[1],
                    strerror(errno));
        }
        fclose(fb);
    }

    return rc;
}













