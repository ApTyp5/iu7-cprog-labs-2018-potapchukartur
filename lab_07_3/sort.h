
#ifndef __SORT_H__
#define __SORT_H__

typedef int(*comparator)(const void *, const void *);

int int_comp(const void *int1, const void *int2);
void el_copy(char *const what, char *const where, int size);
int *binary_seek(char *left_el, char *right_el, const char *const comp_el, comparator, int size);
void move_right(const int *const left_el, int *right_el, const int step);
void mysort(void *start, int len, int size, comparator);

#endif




