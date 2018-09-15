

#ifndef __SORT_H__
#define	__SORT_H__

int intComp(const void *arg1, const void *arg2);
void intElCopy(int *const what, int *const where);
void mysort(void *start, void *end, const int elSize, int (*comparator)(const void *, const void *));
void *binarySeek(int *leftEl, int *rightEl, const int *const compEl, int (*comparator)(const void *, const void *));
void moveRight(const int *const leftEl, int *rightEl, const int step);

#endif
