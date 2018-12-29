#include "headers/list.h"
#include "headers/define.h"
#include "headers/stat.h"
#include <stdio.h>
#include <stdlib.h>



static void fpdata(int i, long int *dtemp, long int *dnum,
                          long int *ntemp, long int *nnum);

static void plist(struct list_head *head)
{
    wea_t *iter;
    list_for_each_entry(iter, head, list)
    {
        printf("%d %d %d %d %d\n", iter->year, iter->mon, iter->day, iter->dtemp, iter->ntemp);
    }
}



int stat(FILE *f, char *fnam)
{
    LIST_HEAD(head);

    while (wea_read(&head, f) == HAPPY_END);

//    plist(&head);

    FILE *fo = fopen(INVESTIGATION_NAME, "w");
    wea_t *iter = list_entry(head.next, wea_t, list);


    unsigned int cur_year = iter->year;
    unsigned int temp = iter->dtemp + iter->ntemp;
    unsigned int num = 1;

    list_for_each_entry(iter, head.next, list)
    {
        if (iter->year != cur_year)
        {
            fprintf(fo, "%d %lf\n", cur_year, temp / num / 10.0 / 2.0);
            cur_year = iter->year;
            temp = 0;
            num = 0;
        }

        temp += iter->dtemp + iter->ntemp;
        num += 1;
    }

    fclose(fo);

    wea_free(&head);

    return HAPPY_END;
}


int wea_read(struct list_head *head, FILE *f)
{
    int year, mon, day, dtemp, ntemp;

    int rc = fscanf(f, "%d%d%d%d%d", &year, &mon, &day, &dtemp, &ntemp);

    if (rc == EOF)
        return EOF;

    if (rc != 5)
        return FILE_FORMAT_ERROR;

    if (! (6 <= mon && mon <= 8))
        return HAPPY_END;

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



void wea_free(struct list_head *head)
{
    wea_t *iter;
    wea_t *n;

    list_for_each_entry_safe(iter, n, head, list)
    {
        free(iter);
    }
}






