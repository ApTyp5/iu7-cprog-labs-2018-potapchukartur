#include "headers/list.h"
#include "headers/define.h"
#include "headers/weather.h"
#include <stdio.h>
#include <stdlib.h>


int proc(FILE *f)
{
    int rc = ALL_GOOD;
    LIST_HEAD(head);
    wea_t *iter;
    int year = -1;
    int maxtemp = -273;
    int mintemp = 100;

    while (( rc = weather_fread(&head, f) ) == HAPPY_END);

    if (rc == EOF)
    {
        printf("Год | разница между температурами (Вариант E)\n");

        list_for_each_entry(iter, &head, list)
        {
            if (iter->year != year)
            {
                if (year != -1)
                {
                    printf("%d.%d\n", (maxtemp - mintemp) / 10,
                            (maxtemp - mintemp) % 10);
                }

                printf("%d ", iter->year);
                year = iter->year;

                maxtemp = -273;
                mintemp =  100;

            }

            if (iter->dtemp > maxtemp)
                maxtemp = iter->dtemp;
            if (iter->ntemp < mintemp)
                mintemp = iter->ntemp;
        }

    }
    printf("%d.%d\n", (maxtemp - mintemp) / 10,
                      (maxtemp - mintemp) % 10);

    weather_free(&head);
    return rc;
}

int weather_free(struct list_head *head)
{
    wea_t *iter;
    wea_t *n;

    list_for_each_entry_safe(iter, n, head, list)
    {
        free(iter);
    }

    return HAPPY_END;
}



int weather_fread(struct list_head *head, FILE *f)
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





