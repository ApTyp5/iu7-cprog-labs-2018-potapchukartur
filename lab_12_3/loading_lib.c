#include <dlfcn.h>
#include "headers/define.h"

#define _GNU_SOURCE
#define NULL    (void *) 0


int load_lab_07_lib(void **dl_ptr,
    int (**safety_frarr)(char *, int **, int **, int **),
    int (**process_int_arr)(int **, int **),
    int (**safety_fparr)(char *, int *, int *))
{
    *dl_ptr = dlopen("./liblab_07.so", RTLD_LAZY);

    if (!dl_ptr)
        return LOAD_ERROR;

    *safety_frarr = dlsym(*dl_ptr, "safety_frarr");

    *process_int_arr = dlsym(*dl_ptr, "process_int_arr");

    *safety_fparr = dlsym(*dl_ptr, "safety_fparr");

    if (!safety_frarr ||
        !process_int_arr ||
        !safety_fparr)
        return LOAD_ERROR;

    return HAPPY_END;
}


