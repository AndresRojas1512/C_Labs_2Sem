#include "matrix_mem.h"

double **matrix_alloc(size_t m, size_t n)
{
    double **matrix = (double **)malloc(m * sizeof(double *));
    if (!matrix)
        return NULL;
    for (size_t i = 0; i < m; i++)
    {
        matrix[i] = (double *)malloc(n * sizeof(double));
        if (!matrix[i])
        {
            matrix_free(matrix, i);
            return NULL;
        }
    }
    return matrix;
}

void matrix_free(double **matrix, size_t m)
{
    for (size_t i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
}