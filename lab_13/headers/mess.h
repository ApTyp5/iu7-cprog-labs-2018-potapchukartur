#ifndef __MESS_H__
#define __MESS_H__

#include <stdio.h>

/**
 * \brief Печать цветного сообщения в файл
 *
 * Если colour == NULL, то печать производится стандартным цветом
 */
void fpmess(FILE *f, char *mess, char *colour);

/// То же самое, что и выше, только f == stdout
void pmess(char *mess, char *colour);

/// pmess(mess, RED)
void perr(char *);
/// pmess(mess, YELLOW)
void pwarn(char *);
/// pmess(mess, BLUE)
void pinfo(char *);


#endif
