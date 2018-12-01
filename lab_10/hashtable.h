
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "listfunc.h"


typedef struct hashtable hash_t;


struct hashtable
{
    int curnum;
    int hashnum;

    node_t *table;
};


/**
 * \brief Создание пустой хэш-таблицы 
 *
 * \return NULL  в случае ошибки выделения памяти,
 * соотв. структуру иначе.
 */
hash_t *ht_create();

//double ht_occup_koeff(hash_t ht);

/**
 * \brief Добавление хэша указателя на *data в таблицу
 * 
 * При превышении коеффициента заполненности некоторого
 * значения (смотри в define.h), таблица расширяется, что
 * не требует дополнительных действий пользователя.
 *
 * Настроить коеффициент заполненности или выключить 
 * авторасширение можно, включив соотв. флаги при
 * компиляции (сморит в define.h)
 */
int ht_add(hash_t *ht, void *data);

/**
 * \brief Проверка наличия элемента в хэш-таблице
 */
int ht_has_data(hash_t *ht, void *data);

// static ht_resize

#endif
