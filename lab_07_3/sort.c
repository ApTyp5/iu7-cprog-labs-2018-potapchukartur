#include <stdlib.h>
#include <stdio.h>

typedef int (*comparator)(const void *, const void *);


int int_comp(const void *int1, const void *int2)
{
    return *(int*)int1 - *(int*)int2;
}


void el_copy(char *what, char *where, int size)
{
    for (int i = 0; i < size; i++)
        *where++ = *what++;
}


int bit_dist(const char *el_1, const char *el_2)
{
    return (abs(el_1 - el_2));
}


char *half_bit_dist(const char *el_1, const char *el_2, int size)
{
    int hbd = bit_dist(el_1, el_2)/2/size;

    for (int i = 0; i < hbd; i++)
        el_1 += size;
    return (char *)el_1;
}
        



//
// Возвращает указатель на первый элемент,
// превышающий или равный *comp_el на ОТРЕЗКЕ [*left_el .. *right_el]
char *binary_seek(const char *left_el, const char *right_el, const char *const comp_el, comparator comp, int size)
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


// 
// Передвигает int-ы на отрезке [*left_el ..  *right_el]
// на size бит вправо
// 
void move_right(const char *const left_el, char *right_el, const int size)
{
    right_el += size - 1;

    for (;right_el >= left_el; right_el--)
    {
        *(right_el + size) = *right_el;
    }
}


void mysort(void *const start, int len, int size, comparator comp)
{
    char *end = (char *)start + len*size;
    char *tmp = malloc(size);
    char *ins_place = NULL;
    char *begin = (char *)start;


    for (begin += size; begin < end; begin += size)
    {
        if (comp(begin, begin - size) < 0)
        {
            el_copy(begin, tmp, size);
            ins_place = binary_seek(start, begin - size, begin, comp, size);
            move_right(ins_place, begin - size, size);
            el_copy(tmp, ins_place, size);
        }
    }

    free(tmp);
}



/*

int main()
{
    int a[10] = {0};
    int *b = a + 10;

    printf("bit_dist = %d\n", bit_dist((char *)a, (char *)b));
    printf("a = %p\n", (void *)a);
    printf("b = %p\n", (void *)b);
    printf("a+b /2 = %p\n", half_bit_dist((char *)a, (char *)b, 4));

    a[3] = 213;
    el_copy((char *)a + 3*4, (char *)a + 4*9, 4);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
   


    return 0;
}

*/
