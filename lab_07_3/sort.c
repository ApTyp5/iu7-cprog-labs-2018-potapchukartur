#include <stdlib.h>
#include <stdio.h>

typedef int (*comparator)(const void *, const void *);



/// Сравнивает целые числа
// \param[in] int1 указатель на начало 1-го числа
// \param[in] int2 указатель на начало 2-го числа
int int_comp(const void *int1, const void *int2)
{
    return *(int*)int1 - *(int*)int2;
}



/// Копирует элемент из одной области памяти в другую
// \param[in] what область памяти, которуая будет копироваться
// \param[out] where область памяти, куда будет копироваться what
// \param[in] size размер входных областей памяти
void el_copy(const char *what, char *where, int size)
{
    for (int i = 0; i < size; i++)
        *where++ = *what++;
}



/// Возвращает расстояние между указателями
int bit_dist(const char *el_1, const char *el_2)
{
    return (abs(el_1 - el_2));
}



///Возвращает указатель на область памяти,
///находящуюся в центре между el_1 и el_2
char *half_bit_dist(const char *el_1, const char *el_2, int size)
{
    int hbd = bit_dist(el_1, el_2) / (2 * size);

    for (int i = 0; i < hbd; i++)
        el_1 += size;
    return (char *)el_1;
}
        




/// Возвращает указатель на первый элемент,
/// превышающий или равный *comp_el на ОТРЕЗКЕ [*left_el .. *right_el]
// \param[in] size размер элементов
// \param[in] comp ф-я сравнивания 2-х элементов
// \param[in] comp_el элемент, место которому будет искаться
// \param[in] left_el левая граница упорядоченного массива
// \param[in] right_el правая граница уаорядоченного массива
char *binary_seek(const char *left_el, const char *right_el,
    const char *const comp_el, comparator comp, int size)
{
    void *tmp;
    while (bit_dist(right_el, left_el) > size)
    {
        tmp = half_bit_dist(left_el, right_el, size);

        if ((comp)(tmp, comp_el) < 0)
        {
            left_el = tmp;
            continue;
        }
        right_el = tmp;
    }

    return (comp)(left_el, comp_el) >= 0 ? (char *)left_el : (char *)right_el;
}


/// Передвигает int-ы на отрезке [*left_el ..  *right_el]
/// на size бит вправо
void move_right(const char *const left_el, char *right_el, const int size)
{
    right_el += size - 1;

    for (;right_el >= left_el; right_el--)
    {
        *(right_el + size) = *right_el;
    }
}


/// Сорирует массив
// \param[in] start начало массива
// \param[in] len   длина массива
// \param[in] size  размер одного элемента
// \param[in] comp  ф-я сравнивания 2-х элементов
void mysort(void *const start, size_t len, size_t size, comparator comp)
{
    char *end = (char *)start + len * size;
    char *tmp = malloc(size);
    char *ins_place = NULL;
    char *begin = (char *)start;

    char *step_back;



    for (begin += size; begin < end; begin += size)
    {
        step_back = begin - size;
        if (comp(begin, step_back) < 0)
        {
            el_copy(begin, tmp, size);
            ins_place = binary_seek(start, step_back, begin, comp, size);
            move_right(ins_place, step_back, size);
            el_copy(tmp, ins_place, size);
        }
    }

    free(tmp);
}



