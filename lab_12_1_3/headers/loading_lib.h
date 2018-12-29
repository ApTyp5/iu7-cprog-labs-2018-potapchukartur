
#ifndef __LOADING_LIB_H__
#define __LOADING_LIB_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

int load_lab_07_lib(void **dl_ptr,
    int (**safety_frarr)(char *, int **, int **, int **),
    int (**process_int_arr)(int **, int **),
    int (**safety_fparr)(char *, int *, int *));

#endif

