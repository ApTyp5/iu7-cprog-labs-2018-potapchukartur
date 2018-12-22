#ifndef __STAT_H__
#define __STAT_H__

#include <stdio.h>
#include "list.h"

typedef struct weather_data wea_t;
struct weather_data
{
    int year;
    int mon;
    int day;
    int dtemp;
    int ntemp;
    struct list_head list;
};


int weather_fread(struct list_head *head, FILE *f);
int proc(FILE *f);
int weather_free(struct list_head *head);

#endif


