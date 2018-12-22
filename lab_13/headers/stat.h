#ifndef __STAT_H__
#define __STAT_H__

#include "list.h"
#include <stdio.h>

typedef struct weather wea_t;
struct weather
{
    int year;
    int day;
    int mon;
    int dtemp;
    int ntemp;
    struct list_head list;
};


int stat(FILE *f, char *fnam);
wea_t *wea_init();
void wea_free(wea_t *weather);
int wea_read(struct list_head *head, FILE *f);


#endif
