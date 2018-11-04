#include <math.h>
#include "define.h"
#include "matrix.h"




int epseq(double el1, double el2)
{
    double ael1 = fabs(el1);
    double ael2 = fabs(el2);

    double maxel = ael1 >= ael2 ? ael1 : ael2;

    if (maxel == 0.0)
        return HAPPY_END;
    
    if (fabs(ael1 - ael2) < EPS * maxel)
        return HAPPY_END;

    return UNHAPPY_END;
}

int mtr_eq(matrix_t mtr1, int m1len, int m1wid,
           matrix_t mtr2, int m2len, int m2wid)
{
    if (m1len != m2len || m1wid != m2wid)
        return UNHAPPY_END;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
            if (mtr1[i][j] != mtr2[i][j])
                return UNHAPPY_END;
    return HAPPY_END;
}

int mtr_epseq(matrix_t mtr1, int m1len, int m1wid,
              matrix_t mtr2, int m2len, int m2wid)
{
    /*
    piv(m1len);
    piv(m1wid);
    piv(m2len);
    piv(m2wid);
    */

    if (m1len != m2len || m1wid != m2wid)
        return UNHAPPY_END;

    for (int i = 0; i < m1len; i++)
        for (int j = 0; j < m1wid; j++)
        {
//            piv(i); piv(j); pdv(mtr1[i][j]); pdv(mtr2[i][j]);

            if (epseq(mtr1[i][j], mtr2[i][j]) == UNHAPPY_END)
                return UNHAPPY_END;
        }

    return HAPPY_END;
}
