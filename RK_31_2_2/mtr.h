
#ifndef __MTR_H__
#define __MTR_H__

typedef int **mtr_t;

mtr_t mtr_create(int len, int wid);

void mtr_free(mtr_t mtr);

int mtr_readMM(mtr_t *mtr, char *fnam);


#endif
