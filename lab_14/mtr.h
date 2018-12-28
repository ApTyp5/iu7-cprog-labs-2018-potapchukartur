#ifndef __MTR_H__
#define __MTR_H__

typedef struct mtr mtr_t;

mtr_t mtr_create(int len, int wid);

int mtr_set(mtr_t, mtr, int raw, int col);

int mtr_get(mtr_t, int raw, int col);

mtr_t mtr_add(mtr_t mtr1, mtr_t mtr2);

mtr_t mtr_mult(mtr_t mtr1, mtr_t mtr2);

#endif
