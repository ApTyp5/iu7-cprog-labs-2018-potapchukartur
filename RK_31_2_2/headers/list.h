#ifndef __LISTM_H__
#define __LISTM_H__

#include <stdlib.h>
#include "list.h"
#include "mtr.h"



typedef struct list_node list_node;


struct list_node
{
    int col;
    int val;

    list_node *next;
};

int min(int, int);
int max(int, int);

/**
 * \brief Перевод обычной матрицы в форму списка смежностей
 */
list_node **convert_mtr_to_lista(mtr_t mtr, int len, int wid);

/**
 * \brief Добавление элемента в конец матрицы
 *
 * Матрица представлена списком смежностей
 * 
 * \param [in] lista массив списков смежностей
 * \param [in] raw   строка добавляющегося элемента
 * \param [in] col   столбец ==//==
 * \param [in] val   значение добавляющегося элемента
 *
 * \return возвращает HAPPY_END при успешном добавлении,
 * ALLOC_ERROR иначе.
 */
int add_back(list_node **lista, int raw, int col, int val);


/**
 * \brief Поиск по количественно-дружественным характеристикам
 * 
 * \param [in] lista массив списков смежностей
 * \param [in] len   длина массива ==//==
 * \param [in] comp  ф-я сравнения друзей
 *
 * Если в качестве ф-ии comp передать ф-ю мах (см. выше), то
 * friend_research вернет номер человека с максимальным кол-вом друзей,
 * с функцией min наоборот.
 */
int friend_research(list_node **lista, int len, int comp(int, int));


/**
 * \brief Проверка дружбы
 *
 * Проверяет, дружит ли who с whom
 *
 * \param [in] lista массив списков смежностей
 * \param [in] len   длина массива ==//==
 *
 * \return YES, если who дружит с whom,
 *         NO иначе.
 */
int is_friend(list_node **lista, int len, int who, int whom);


/**
 * \brief Освобождение памяти из-под списка смежноти
 */
void list_free(list_node **lista, int len);




#endif


