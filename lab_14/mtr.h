#ifndef __MTR_H__
#define __MTR_H__

typedef struct mtr mtr_t;
#define mtr_el  int

#define HAPPY_END       0
#define ALLOCATION_E    -1
#define OUT_OF_RANGE    -2
#define BAD_ADD_SIZE    -3
#define BAD_MUL_SIZE    -4

/**
 * \brief Создание матрицы
 *
 * \len длина
 * \wid ширина
 *
 * \return указатель на матрицу, если выделение памяти
 * прошло успешно, NULL иначе
 *
 * Матрица инициализируется нулями
 */
mtr_t *mtr_create(int len, int wid);


/**
 * \brief установка значения элементу матрицы
 *
 * \mtr указатель на матрицу
 * \raw строчное положение значения в матрице
 * \col столбцовое положение значения в матрице
 *
 * индексы матрицы считаются с 0
 * 
 * \return 0, если задание переменной прошло успешено,
 * -2, если была попытка выйти за границы матрицы
 * -1, если произошла ошибка выделения памяти
 *
 */
int mtr_set(mtr_t *mtr, int raw, int col, mtr_el val);


/**
 * \brief извлечение значения из матрицы
 *
 * \mtr указатель на матрицу
 * \raw строчное положение значения в матрице
 * \col столбцовое положение значения в матрице
 * \cont = container, т.е. указатель на место
 *  записи извлекаемого элемента
 *
 * индексы матрицы считаются с 0
 *
 * \return 0, если извлечение прошло успешено,
 * -2, если была попытка выйти за границы матрицы
 *
 */
int mtr_get(mtr_t *mtr, int raw, int col, mtr_el *cont);


/**
 * \brief сложение матриц
 *
 * \mtr1 указатель на 1-ю матрицу-слагаемое
 * \mtr2 указатель на 2-ю матрицу-слагаемое
 *
 * \return 0, если сложение прошло успешено,
 *  -1, если произошла ошибка выделения памяти
 *  -3, если были поданы матрицы несоответствующих размеров
 *
 * Программа корректно обрабатывает ситуацию, когда
 * в качестве указателя на результат передается 
 * указатель на одно из слагаемых
 *
 * \warning указатель result должен быть либо действующей
 *  матрицей, либо проинициализирован NULL
 *
 *  Если result == NULL, результат не определен
 */
int mtr_add(mtr_t *mtr1, mtr_t *mtr2, mtr_t **result);


/**
 * \brief умножение матриц
 *
 * \mtr1 указатель на 1-ю матрицу-множитель
 * \mtr2 указатель на 2-ю матрицу-множитель
 *
 * \return 0, если извлечение прошло успешено,
 *  -1, если произошла ошибка выделения памяти
 *  -4, если были поданы матрицы несоответствующих размеров
 *
 * Программа корректно обрабатывает ситуацию, когда
 * в качестве указателя на результат передается 
 * указатель на одно из слагаемых
 *
 * \warning указатель *result должен быть либо действующей
 *  матрицей, либо проинициализирован NULL
 *
 *  Если result == NULL, результат не определен
 */
int mtr_mult(mtr_t *mtr1, mtr_t *mtr2, mtr_t **result);


/**
 * \brief освобождение памяти из-под матрицы
 *
 * корретно обрабатывает нулевой указатель
 */
void mtr_free(mtr_t *mtr);

#endif

