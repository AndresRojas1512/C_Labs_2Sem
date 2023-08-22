#include "in_out.h"

int input_matrix_sizes(size_t *n, size_t *m)
{
    int exit_code = EXIT_SUCCESS;
    printf("Enter the number of rows:");
    if (scanf("%zu", n) != NUMBER_OF_ARGUMENTS || *n < MINIMUM_SIZE || *n > MAX_GENERAL_SIZE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        printf("Enter the number of columns:");
        if (scanf("%zu", m) != NUMBER_OF_ARGUMENTS || *m < MINIMUM_SIZE || *m > MAX_GENERAL_SIZE)
        {
            exit_code = EXIT_FAILURE;
        }
    }
    return exit_code;
}

int input_matrix(matrix mtrx, size_t n, size_t m)
{
    int exit_code = EXIT_SUCCESS;

    for (size_t i = 0; i < n && exit_code == EXIT_SUCCESS; i++)
    {
        for (size_t j = 0; j < m && exit_code == EXIT_SUCCESS; j++)
        {
            printf("Enter the element: ");
            if (scanf("%d", &(mtrx[i][j])) != NUMBER_OF_ARGUMENTS)
            {
                exit_code = EXIT_FAILURE;
            }
        }
    }
    
    return exit_code;
}

void print_array(int *array, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}