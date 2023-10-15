#include "matrix_io.h"

int matrix_read(double **matrix, size_t m, size_t n)
{
    int exit_code = EXIT_SUCCESS;
    for (size_t i = 0; i < m && !exit_code; i++)
    {
        for (size_t j = 0; j < n && !exit_code; j++)
        {
            if (scanf("%lf", &matrix[i][j]) != 1)
                exit_code = ERROR_READ_MATRIX;
        }
    }
    return exit_code;
}

int sizes_read(size_t *m, size_t *n)
{
    int exit_code = EXIT_SUCCESS;
    if (scanf("%zu %zu", m, n) != 2)
        exit_code = ERROR_SCAN;
    else if (!(*m) || !(*n))
        exit_code = ERROR_SIZE_RANGE;
    return exit_code;
}

int matrix_create(double ***matrix, size_t *m, size_t *n)
{
    int exit_code = EXIT_SUCCESS;
    *matrix = NULL;
    if (sizes_read(m, n))
        return ERROR_SIZE_RANGE;
    // printf("\tSizes: %zu %zu\n", *m, *n);
    *matrix = matrix_alloc(*m, *n);
    if (!matrix)
        return ERROR_MATRIX_ALLOC;
    exit_code = matrix_read(*matrix, *m, *n);
    if (exit_code)
    {
        matrix_free(*matrix, *m);
        *matrix = NULL;
    }
    return exit_code;
}

void matrix_output(double **matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
            printf("%f ", matrix[i][j]);
        printf("\n");
    }
}