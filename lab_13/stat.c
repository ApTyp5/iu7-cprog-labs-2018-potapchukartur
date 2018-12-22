#include "headers/list.h"
#include "headers/define.h"
#include "headers/stat.h"
#include <stdio.h>
#include <stdlib.h>



static void fpdata(int i, long int *dtemp, long int *dnum,
                          long int *ntemp, long int *nnum);



int stat(FILE *f, char *fnam)
{
    LIST_HEAD(head);

    while (wea_read(&head, f) == HAPPY_END);

    FILE *fo = fopen("qwer", "w");
    wea_t *iter;

    for (int i = 0; i < MONTHS; i++)
    {
        long int dtemp[DAYS];
        long int dnum[DAYS];

        long int ntemp[DAYS];
        long int nnum[DAYS];

        list_for_each_entry(iter, &head, list)
        {
            if (iter->mon == i + 1)
            {
                dtemp[iter->day - 1] += iter->dtemp;
                dnum[iter->day - 1] += 1;

                ntemp[iter->day - 1] += iter->ntemp;
                nnum[iter->day - 1] += 1;
            }
        }

        fpdata(i, dtemp, dnum, ntemp, nnum);

        // TODO: вывод графика
    }

    return HAPPY_END;
}

static void fpdata(int i, long int *dtemp, long int *dnum,
                          long int *ntemp, long int *nnum)
{
    char buf[20];
    snprintf(buf, 20, "%s/month_%d", INVDIR, i + 1);

    FILE *f = fopen(buf, "w");

    for (int i = 0; i < DAYS; i++)
    {
        fprintf(f, "%ld %ld\n", (dtemp[i]), dnum[i]);
//        fprintf(f, "%lf\n", (double) (dtemp[i]) / (double) (dnum[i]));
    }
}




int wea_read(struct list_head *head, FILE *f)
{
    int year, mon, day, dtemp, ntemp;

    int rc = fscanf(f, "%d%d%d%d%d", &year, &mon, &day, &dtemp, &ntemp);

    if (rc == EOF)
        return EOF;

    if (rc != 5)
        return FILE_FORMAT_ERROR;

    wea_t *next = malloc(sizeof(wea_t));
    if (!next)
        return ALLOC_ERROR;

    next->year = year;
    next->day = day;
    next->mon = mon;
    next->dtemp = dtemp;
    next->ntemp = ntemp;

    list_add_tail(&(next->list), head);

    return HAPPY_END;
}





