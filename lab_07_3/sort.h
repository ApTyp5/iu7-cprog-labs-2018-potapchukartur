
#ifndef __SORT_H__
#define __SORT_H__

typedef comparator int(*)(const void *, const void *);

int int_comp(const void *int1, const void *int2);
void int_el_copy(int *const what, int *const where);
int *binary_seek(int *left_el, int *right_el, const int *const comp_el, comparator);
void move_right(const int *const left_el, int *right_el, const int step);
void mysort(void *start, int len, int size, comparator);

#endif




