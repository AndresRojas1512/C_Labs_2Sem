#include "process.h"

int process(FILE *file, int *count)
{
    int prev2, prev1, current;
    int exit_code = EXIT_SUCCESS;
    *count = 0;
    int valid_args = 0;
    if (fscanf(file, "%d %d", &prev2, &prev1) != NUM_READ_FIRST_TWO)
    {
        exit_code = EXIT_NOT_ENOUGH_DATA;
    }
    else
    {
        valid_args += 2;
        while (exit_code == EXIT_SUCCESS && fscanf(file, "%d", &current) == ARGS_NUM)
        {
            if (prev1 > prev2 && prev1 > current)
            {
                (*count)++;
            }
            prev2 = prev1;
            prev1 = current;
            valid_args++; // uno mas
        }
        if (valid_args == 2)
        {
            exit_code = EXIT_NOT_ENOUGH_DATA;
        }
    }
    return exit_code;
}