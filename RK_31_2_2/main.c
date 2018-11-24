#include "define.h"
#include "mtr.h"
#include "list.h"


void exersize_9(list_node **, int, int);


int main(int ac, char **av)
{
    int rc = ALL_GOOD;
    int len, wid;


    mtr_t mtr = NULL;

    rc = mtr_readMM(&mtr, av[1], &len, &wid);

    list_node **lista = convert_mtr_to_lista(mtr, len, wid);

    exersize_9(lista, len, wid);

    mtr_free(mtr);
    // Освоб мас списк 
    
    return rc;
}


void exersize_9(list_node **lista, int len, int wid)
{
    return;
}





