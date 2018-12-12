#include <stdio.h>
#include "headers/define.h"
#include "headers/mtr.h"
#include "headers/list.h"



void exersize_9(list_node **, int);


int main(int ac, char **av)
{
    int rc = ALL_GOOD;
    int len, wid;
    mtr_t mtr = NULL;

    rc = mtr_readMM(&mtr, av[1], &len, &wid);
    list_node **lista = convert_mtr_to_lista(mtr, len, wid);


    exersize_9(lista, len);


    mtr_free(mtr);
    list_free(lista, len);
    
    return rc;
}





void exersize_9(list_node **lista, int len)
{
    int max_friendly = friend_research(lista, len, max);
    int min_friendly = friend_research(lista, len, min);

    int is_min_friend_max = is_friend(lista, len, min_friendly,
                                                  max_friendly);
    int is_max_friend_min = is_friend(lista, len, max_friendly,
                                                  min_friendly);

    min_friendly++;
    max_friendly++;

    printf("Номер человека с максимальным кол-вом друзей: %d\n",
        max_friendly);

    printf("Номер человека с минимальным кол-вом друзей: %d\n",
        min_friendly);

    printf("\n");

    if (max_friendly == min_friendly)
    {
        if (is_max_friend_min || is_min_friend_max)
            printf("Этот человек дружит с самим собой.\n");
        else
            printf("Этот человек не желает дружить с собой.\n");

        return;
    }

    if (is_min_friend_max & is_max_friend_min)
    {
        printf("Эти люди дружат друг с другом.\n");
    }
    else if (is_min_friend_max)
    {
        printf("Человек %d дружит с %d. Не взаимно.\n",
            min_friendly, max_friendly);
    }
    else if (is_max_friend_min)
    {
        printf("Человек %d дружит с %d. Не взаимно.\n",
            max_friendly, min_friendly);
    }
    else
        printf("Эти люди не дружат друг с другом.\n");
}





