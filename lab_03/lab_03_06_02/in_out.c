#include "in_out.h"

int input_matrix_size(size_t *size)
{
    int exit_code = EXIT_SUCCESS;
    *size = 0;
    if (scanf("%zu", size) != NUMBER_OF_ARGUMENTS || *size < MINIMUM_SIZE || *size > MAX_GENERAL_SIZE)
    {
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}

void print_matrix(matrix mtrx, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", mtrx[i][j]);
        }
        printf("\n");
    }
}