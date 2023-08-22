#include "logic.h"

int calc_average(FILE *file, double *average)
{
    int exit_code = EXIT_SUCCESS;
    double sum = 0;
    int count = 0, number;
    while (fscanf(file, "%d", &number) != EOF)
    {
        sum += number;
        count++;
    }
    rewind(file);
    if (count == 0)
        exit_code = ERROR_EMPTY;
    else
        *average = sum / count;
    return exit_code;
}

int calc_variance(FILE *file, double average, double *variance)
{
    double sum = 0;
    int count = 0, number;
    int exit_code = EXIT_SUCCESS;
    double diff;
    while (fscanf(file, "%d", &number) != EOF)
    {
        diff = number - average;
        sum += diff * diff;
        count++;
    }
    rewind(file);
    if (count <= 1)
        exit_code = ERROR_CANNOT_CALC_VARIANCE;
    else
        *variance = sum / count;
    return exit_code;
}