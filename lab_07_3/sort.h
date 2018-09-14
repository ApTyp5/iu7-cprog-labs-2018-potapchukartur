

#ifndef __SORT_H__
#define	__SORT_H__

int intComp(void *arg1, void *arg2);
void mysort(void *start, void *end, int elSize, int (*comparator)(void *, void *));
void *binarySeek(int *leftEl, int *rightEl, int *compEl, int (*comparator)(void *, void *));
void moveRight(int *rightEl, int *leftEl, int step);

#endif
