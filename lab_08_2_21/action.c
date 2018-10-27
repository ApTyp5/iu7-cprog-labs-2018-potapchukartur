
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "define.h"
#include "aplog.h"

int do_action(char act,
    matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid);

// Проверка файлов
int try_action(int ac, char *av[])
{
#ifdef  JOURNAL
    LOG_IN;
#endif

    int rc = HAPPY_END;

    matrix_t mtr1 = NULL;
    int m1len = 0;
    int m1wid = 0;

    matrix_t mtr2 = NULL;
    int m2len = 0;
    int m2wid = 0;

    matrix_t ans = NULL;
    int anslen = 0;
    int answid = 0;


    mtr1 = get_mtr(av[2], &m1len, &m1wid, &rc);
#ifdef  JOURNAL
    PS(recieved mtr1:\n);
    PM(%lf\40, mtr1, m1len, m1wid);
#endif

    
    if (strcmp(av[1], "o"))
    {
        mtr2 = get_mtr(av[3], &m2len, &m2wid, &rc);
#ifdef  JOURNAL
        PS(recieved mtr2:\n);
        PM(%lf\40, mtr2, m2len, m2wid);
#endif
    }



    if (!rc)
        rc = do_action(*av[1],
            mtr1, m1len, m1wid,
            mtr2, m2len, m2wid,
            &ans, &anslen, &answid);

    if (!rc)
    {
#ifdef  JOURNAL
        PS(answer mtr:\n);
        PM(%lf\40, ans, anslen, answid);
#endif
  
        rc = strcmp(av[1], "o") ? 
            put_mtr(ans, anslen, answid, av[4]) :
            put_mtr(ans, anslen, answid, av[3]);
    }


#ifdef  JOURNAL
    PV(rc = %d\n, rc);
    LOG_OUT;
#endif

    free(ans);
    free(mtr1);
    free(mtr2);

    return rc;
}



int do_action(char act,
    matrix_t mtr1, int m1len, int m1wid,
    matrix_t mtr2, int m2len, int m2wid,
    matrix_t *ans, int *anslen, int *answid)
{
#ifdef  JOURNAL
    LOG_IN; LOG_OUT;
#endif

    switch (act)
    {
        case 'a':
            return mtr_add(mtr1, m1len, m1wid,
                mtr2, m2len, m2wid,
                ans, anslen, answid);
        case 'm':
            return mtr_mult(mtr1, m1len, m1wid, 
                mtr2, m2len, m2wid, 
                ans, anslen, answid);
        case'o':
            return mtr_ghauss(mtr1, m1len, m1wid,
                ans, anslen, answid);
    }

    return HAPPY_END;
}





