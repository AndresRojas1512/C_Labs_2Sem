#include "main.h"

int main(int argc, char *argv[])
{
    FILE *file;
    int exit_code = EXIT_SUCCESS;
    double average;
    double variance;
    if (argc != NUM_VALID_ARGS)
        exit_code = ERROR_USAGE;
    else
    {
        file = fopen(argv[1], "r");
        if (!file)
            exit_code = ERROR_OPENING_FILE;
        else
        {
            exit_code = calc_average(file, &average);
            if (!exit_code)
            {
                exit_code = calc_variance(file, average, &variance);
                if (!exit_code)
                {
                    fprintf(stdout, "%lf", variance);
                }
            }
        }
    }
    fclose(file);
    return exit_code;
}
