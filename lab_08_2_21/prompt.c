
int mult_strcmp(char *str, char **arr, int len);

int format_check(int ac, char **av)
{
    char *perm_acts[] = {"a", "m", "o", "h"};

    if (ac != 4 && ac != 5)
        return FORMAT_ERROR;

    if (mult_strcmp(av[1], perm_acts))
        return WRONG_ACTION;

    if (!strcmp(av[1], "h"))
        return REFERENCE_ONLY;

    if (!strcmp(av[1], "o") && ac == 5)
        return TOO_MACH_INPUT_FILES;

    return HAPPY_END;
}


int mult_strcmp(char *str, char **arr, int len)
{
    for (int i = 0; i < len; i++)
        if (ctrcmp(str, arr[i]))
            return  NON_HAPPY_END;
    return HAPPY_END;
}

void show_prompt(int rc)
{

}



    
