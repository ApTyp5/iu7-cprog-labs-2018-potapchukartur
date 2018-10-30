


#ifndef __PREPARE_H__ 
#define __PREPARE_H__

#include "define.h"

int format_check(int ac, char **av);
void show_prompt(int rc);
void prepare_args(char *av[], str_t *fin, str_t *fout, str_t *ser, str_t *rep);

#endif


