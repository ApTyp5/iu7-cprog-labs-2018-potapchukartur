
#ifndef __DEB_H__
#define __DEB_H_



/* Метка для проверки передачи управления                                               */
#define     db               printf("db\n")



/* Печать универсального сообщения                                                      */
#define     ps(str)          printf(#str)



/* Печать универсальной переменной (включая строки)                                     */
#define     pv(fstr, val)    printf(#fstr, val)



/* Печать специализированных переменных (включая строки)                                */

// Печать integer-a
#define     piv(inte)       printf(#inte" = %d\n", inte)

// Печать double-a
#define     pdv(doub)       printf(#doub" = %lf\n", doub)

// Пеать char-a
#define     pcv(cha)        printf(#cha" = %c\n", cha)

// Печать string-a
#define     psv(str)        printf(#str" = %s\n", str)



/* Печать универсальных структур (ftype - строка форматирования, не заключенная в "")   */

// Печать массива 'arr' длины 'len'
// fstr - formating string: строка форматирования для каждого члена массива.
// P.S. в fstr передавать строку, не заключенную в вдойные кавычки с 
// синтаксисом первого аргумента семейства функций printf
#define     parr(fstr, arr, len)       for (int i = 0; i < len; i++)   \
                                             printf(#fstr" ", arr[i]); \
                                         printf("\n")

// Печать матрицы 'mat' размерности 'len' на 'wid'
// fstr заполняется по вышеописаным правилам
#define     pmat(ftype, mat, len, wid)  for (int i = 0; i < len; i++)   \
                                             for (int j = 0; j < wid; j++)  \
                                                printf(#ftype"%s", mat[i][j],   \
                                                    (j + 1) % wid ? " " : "\n")

#endif // __DEB_H__ 
