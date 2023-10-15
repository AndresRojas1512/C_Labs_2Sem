#include "matrix_op.h"

void find_max(double **matrix, size_t m, size_t n, size_t *col_index, size_t *row_index)
{
    double max = matrix[0][0];
    *col_index = 0;
    *col_index = 0;
    for (size_t j = 0; j < n; j++)
    {
        for (size_t i = 0; i < m; i++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                *col_index = j;
                *row_index = i;
            }
        }
    }
}

int delete_column(double **matrix, size_t m, size_t *n, size_t col_index)
{
    int exit_code = EXIT_SUCCESS;
    if (!matrix || col_index >= *n)
        exit_code = EXIT_FAILURE;
    else
    {
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = col_index; j < (*n) - 1; j++)
                matrix[i][j] = matrix[i][j + 1];
            double *tmp = (double *)realloc(matrix[i], ((*n) - 1) * sizeof(double));
            if (!tmp)
                exit_code = EXIT_FAILURE;
            else
                matrix[i] = tmp;
        }
        (*n)--;
    }
    return exit_code;
}

int delete_row(double ***matrix, size_t *m, size_t row_index)
{
    int exit_code = EXIT_SUCCESS;
    if (!(*matrix))
        exit_code = EXIT_FAILURE;
    else
    {
        free((*matrix)[row_index]);
        for (size_t i = row_index; i < (*m) - 1; i++)
            (*matrix)[i] = (*matrix)[i + 1];
        double **tmp = (double **)realloc(*matrix, ((*m)-1) * sizeof(double));
        if (!tmp)
            exit_code = EXIT_FAILURE;
        else
        {
            *matrix = tmp;
            (*m)--;
        }
    }
    return exit_code;
}

int form_square_matrix(double ***matrix, size_t *m, size_t *n)
{
    int exit_code = EXIT_SUCCESS;
    if (!(*matrix))
        exit_code = EXIT_FAILURE;
    else
    {
        size_t col_index;
        size_t row_index;
        if ((*m) > (*n)) // mas filas que columnas
        {
            while ((*m) != (*n))
            {
                find_max(*matrix, *m, *n, &col_index, &row_index);
                delete_row(matrix, m, row_index);
            }
        }
        else if ((*m) < (*n)) // mas columas que filas
        {
            while ((*m) != (*n))
            {
                find_max(*matrix, *m, *n, &col_index, &row_index);
                delete_column(*matrix, *m, n, col_index);
            }
        }
    }
    return exit_code;
}

int add_row(double ***matrix, size_t *m, size_t n)
{
    int exit_code = EXIT_SUCCESS;
    if (!(*matrix))
        exit_code = EXIT_FAILURE;
    else
    {
        double **tmp_ptr = (double **)realloc(*matrix, ((*m) + 1) * sizeof(double *));
        if (!tmp_ptr)
            exit_code = EXIT_FAILURE;
        else
        {
            *matrix = tmp_ptr;
            (*m)++;
            double *tmp_row_ptr = (double *)calloc(n, sizeof(double));
            if (!tmp_row_ptr)
                exit_code = EXIT_FAILURE;
            else
            {
                (*matrix)[(*m) - 1] = tmp_row_ptr;
                for (size_t i = 0; i < n; i++)
                    (*matrix)[(*m) - 1][i] = calc_column_mean(*matrix, *m, i);
            }
        }
    }
    return exit_code;
}

double calc_column_mean(double **matrix, size_t m, size_t col_index)
{
    double mean = 0;
    for (size_t i = 0; i < m - 1; i++)
        mean += matrix[i][col_index];
    mean = floor(mean / (m - 1));
    return mean;
}

int add_colum(double **matrix, size_t m, size_t *n)
{
    int exit_code = EXIT_SUCCESS;
    if (!matrix)
        exit_code = EXIT_FAILURE;
    else
    {
        for (size_t i = 0; i < m; i++)
        {
            double *tmp = (double *)realloc(matrix[i], ((*n) + 1) * sizeof(double));
            if (!tmp)
                exit_code = EXIT_FAILURE;
            else
            {
                matrix[i] = tmp;
                matrix[i][(*n)] = 0.0;
            }
        }
        (*n)++;
        for (size_t i = 0; i < m; i++)
            matrix[i][(*n) - 1] = calc_row_min(matrix, *n, i);
    }
    return exit_code;
}

double calc_row_min(double **matrix, size_t n, size_t row_index)
{
    double min = matrix[row_index][0];
    for (size_t j = 0; j < n - 1; j++)
    {
        if (matrix[row_index][j] < min)
            min = matrix[row_index][j];
    }
    return min;
}

int prepare_square_matrices(double ***matrix_a, size_t *m, size_t *n, double ***matrix_b, size_t *p, size_t *q)
{
    int exit_code = EXIT_SUCCESS;
    if (*m < *p) // matriz a es menor que b
    {
        while (*m != *p)
        {
            exit_code = add_row(matrix_a, m, *n);
            if (!exit_code)
                exit_code = add_colum(*matrix_a, *m, n);
        }
    }
    else if (*m > *p) // matriz a es mayor que b
    {
        while (*m != *p)
        {
            exit_code = add_row(matrix_b, p, *q);
            if (!exit_code)
                exit_code = add_colum(*matrix_b, *p, q);
        }
    }
    return exit_code;
}

// Multiplication rho and gamma
void matrix_multiply(double **matrix_a, size_t m, size_t n, double **matrix_b, size_t p, size_t q, double **matrix_c, size_t *r, size_t *c) // done
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < q; j++)
        {
            matrix_c[i][j] = 0;
            for (size_t k = 0; k < p; k++)
            {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    *r = n;
    *c = p;
}

void matrix_square_copy(double **matrix_dst, double **matrix_src, size_t m, size_t n) // done
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix_dst[i][j] = matrix_src[i][j];
        }
    }
}

void calc_mult_times(size_t rho, size_t *count_square_power, size_t *count_rest) // done
{
    if (!rho || rho == 1)
    {
        *count_square_power = 0;
        *count_rest = 0;
    }
    size_t base = 2;
    *count_square_power = 0;
    *count_rest = 0;
    while (base <= rho)
    {
        (*count_square_power)++;
        base *= 2;
    }
    *count_rest = (size_t)(rho - pow(2, *count_square_power));
}

int matrix_power(double **matrix_m, size_t m, size_t n, double ***matrix_r, size_t *r, size_t *c, size_t count_square_power, size_t count_rest, size_t rho)
{
    *matrix_r = matrix_alloc(m, n);
    double **tmp1 = matrix_alloc(m, n);
    if (!tmp1)
        return EXIT_FAILURE;
    if (!rho)
    {
        *r = m;
        *c = n;
        matrix_entity(tmp1, m, n);
        matrix_square_copy(*matrix_r, tmp1, *r, *c);
        return EXIT_SUCCESS;
    }
    if (rho == 1)
    {
        *r = m;
        *c = n;
        matrix_square_copy(*matrix_r, matrix_m, *r, *c);
        return EXIT_SUCCESS;
    }
    double **tmp2 = matrix_alloc(m, n);
    if (!tmp2)
        return EXIT_FAILURE;
    matrix_square_copy(tmp1, matrix_m, m, n);
    for (size_t i = 0; i < count_square_power; i++)
    {
        matrix_multiply(tmp1, m, n, tmp1, m, n, tmp2, r, c);
        matrix_square_copy(tmp1, tmp2, m, n);
    }
    for (size_t i = 0; i < count_rest; i++)
    {
        matrix_multiply(tmp1, m, n, matrix_m, m, n, tmp2, r, c);
        matrix_square_copy(tmp1, tmp2, m, n);
    }
    matrix_square_copy(*matrix_r, tmp1, m, n);
    return EXIT_SUCCESS;
}

void matrix_entity(double **matrix, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}