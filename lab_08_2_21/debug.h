
#ifndef __DEB_H__
#define __DEB_H_

// Метка для проверки передачи управления
#define     db               printf("db\n")

// Печать универсального сообщения
#define     ps(str)          printf(#str)

// Печать универсальной переменной (включая строки)
#define     pv(fstr, val)    printf(#fstr, val)

// Печать специализированных переменных (включая строки)
#define     piv(inte)       printf(#inte" = %d\n", inte)
#define     pdv(doub)       printf(#doub" = %lf\n", doub)
#define     pcv(cha)        printf(#cha" = %c\n", cha)
#define     psv(str)        printf(#str" = %s\n", str)

// Печать универсальных структур (ftype - строка форматирования, не заключенная в "")
#define     parr(ftype, arr, len)       for (int i = 0; i < len; i++)   \
                                             printf(#ftype" ", arr[i]); \
                                         printf("\n")

#define     pmat(ftype, mat, len, wid)  for (int i = 0; i < len; i++)   \
                                             for (int j = 0; j < wid; j++)  \
                                                printf(#ftype"%s", mat[i][j],   \
                                                    (j + 1) % wid ? " " : "\n")

#endif // __DEB_H__ 
