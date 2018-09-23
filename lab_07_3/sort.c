
typedef int (*comparator)(const void *, const void *);

int int_comp(const void *int1, const void *int2)
{
    return *(int*)int1 - *(int*)int2;
}



void int_el_copy(int *const what, int *const where)
{
    *where = *what;
}

//
// Возвращает указатель на первый элемент,
// превышающий или равный *compEl на ОТРЕЗКЕ [*leftEl .. *rightEl]
int *binary_seek(int *leftEl, int *rightEl, const int *const compEl, comparator comp)
{
    int *tmp;
    while (rightEl - leftEl > 1)
    {
        tmp = leftEl;
        for (int i = 0; i < (rightEl - leftEl)/2; i++)
            tmp += 1;

        if ((comp)(tmp, compEl) < 0)
        {
            leftEl = tmp;
            continue;
        }

        rightEl = tmp;
    }



    return *leftEl >= *compEl ? leftEl : rightEl;
}

// 
// Передвигает int-ы на отрезке [*leftEl ..  *rightEl]
// на step шагов вправо
// 
void move_right(const int *const leftEl, int *rightEl, const int step)
{
    for ( ; rightEl > leftEl - 1; rightEl--)
    {
        *(rightEl + step) = *rightEl;
    }
}



void mysort(void *start, int len, int size, comparator comp)
{
    int *end = (int *)start + len;
    int tmp;
    int *ins_place;

    for (int *begin = start; begin < end; begin++)
        if (comp(begin, begin - 1) < 0)
        {
            tmp = *begin;
            ins_place = binary_seek(start, begin - 1, begin, comp);
            move_right(ins_place, begin - 1, 1);
            *ins_place = tmp;
        }
}





