#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "fileworks.h"


/**
 * \brief Открытие файла
 *
 * Открывает файл и проверяет успех операции
 *
 * \param[in] filename имя файла
 * \param[in] mod   режим открытия 
 * \param[out] rc   указатель на переменную, содержащую код ошибки
 */
FILE *fopen_try(const char *const filename, const char *const mod, int *const rc)
{
    FILE *tmp = NULL;
    tmp = fopen(filename, mod);

    *rc = (tmp == NULL ? FOPEN_ERROR : HAPPY_END);

    return tmp;
}



/**
 * \brief Проверяет файл целых чисел
 *
 * Возвращает WRONG_INPUT, в файле содержатся не только
 * целые числа, иначе возвращает их количество
 */
int fint_check(FILE *f)
{
    rewind(f);
    int read = 0;
    int len = 0;
    int sig = 1;

    for (; (sig = fscanf(f, "%d", &read)) > 0; len++);
    if (sig)
        return len;

    return WRONG_INPUT;
}



/**
 * \brief Проверяет файл целых чисел
 *
 * Действует аналогично fint_check, но при
 * подаче на вход пустого файла возвращает 
 * EMPTY_FILE
 */
int file_check(FILE *f, int *const len)
{

    *len = fint_check(f);
    switch (*len)
    {
        case WRONG_INPUT:
            return WRONG_INPUT;
        case 0:
            return EMPTY_FILE;
        default:
            return HAPPY_END;
    }
}



/**
 * \brief Считывает массив целых чисел из файла
 * 
 * Также ф-я может выделить доп место для переменных,
 * которые будут находиться перед началом массива
 *
 * \param[in] f указатель на открытый файл
 * \param[in] len длина входного массива
 * \param[out] *pb указатель на начало считанного массива
 * \param[out] *pe указатель на область за концом считанного массива
 * \param[in] add количество дополнительных ячеек
 * \param[out] rc указатель на код ошибки
 */
int *frarr(FILE *f, int len, int **pb, int **pe, int add,
        int *const rc)
{
    *pb = (int *)malloc((len + add) * sizeof(int));
    if(*pb == NULL)
    {
        *rc = ALLOCATION_ERROR;
        return NULL;
    }

    *pb += add;// Доп. элементы для доп. информации
    *pe = *pb;

    rewind(f);
    for (int i = 0; i < len; i++)
        fscanf(f, "%d", (*pe)++);

    return *pb - add;
}



/**
 * \brief Записывает в файл массив целых чисел
 * \param[in] f указатель на открытый  файл
 * \param[in] pb указатель на начало массива
 * \param[in] pe указатель на область за последним элементом массива
 */
void fparr(FILE *f, const int *pb, const int *pe)
{
    rewind(f);
    for (; pe > pb; fprintf(f, "%d ", *pb++));
    fprintf(f, "\n");
}



