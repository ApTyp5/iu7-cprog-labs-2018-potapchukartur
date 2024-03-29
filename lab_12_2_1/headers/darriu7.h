#ifndef __VECTOR_H
#define __VECTOR_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE        10
#define PRIVAT_DATA_SIZE    2

// Yeld codes
#define IU7_FAIL    -1
#define IU7_SUCESS  0

// Чтобы понять смысл следующи define-ов,
// смотрите ф-ю 'create'
#define CUR_LEN (darr[-1])
#define MAX_LEN (darr[-2])

typedef int * darriu7;


/*  Создание дин. массива длины len  */
/*************************************/
// --> Вход : длина массива
// --> Выход: указатель на начало массива при успешном
// выделении памяти и корректности входных даннх, 
// NULL иначе
darriu7 darriu7_create(int len);


/*  Вывод текущей дины      */
/****************************/
// --> Вход : дин. массив
// --> Выход: длина массива
// в случае корректных данных,
// IU7_FAIL иначе
int darriu7_len(darriu7 darr);


/*  Вывод coдержимого динамического массива на экран  */
/******************************************************/
// --> Вход : дин. массив
void darriu7_print(darriu7 darr);


/* Добавление элемента в конец дин. массива  */
/*********************************************/
// --> Вход : дин. массив, значение элемента,
// который хотим добавить
// --> Выход: адрес получившегося дин. массива.
darriu7 darriu7_append(darriu7 darr, int x);



/* Освобождение памяти из-под дин. массива */
/*******************************************/
// --> Вход: дин. массив.
void darriu7_release(darriu7 darr);


#endif
