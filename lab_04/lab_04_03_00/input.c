#include "input.h"

int read_line(char *str)
{
    int exit_code = EXIT_SUCCESS;
    if (fgets(str, STRING_MAX_LEN, stdin) == NULL)
        exit_code = EXIT_UB;
    else if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
        exit_code = EXIT_SUCCESS;
    }
    else if (strcmp(str, "") == 0)
        exit_code = EXIT_EMPTY_STRING;
    else
        exit_code = EXIT_LONG_STRING;
    return exit_code;
}