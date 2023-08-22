#include "main.h"

int main()
{
    int exit_code = EXIT_FAILURE;
    size_t n, m;
    matrix mtrx;
    int array[M_MAX_COLUMNS];

    if (!input_matrix_sizes(&n, &m))
    {
        printf("Enter the elements of the matrix: ");
        if (!input_matrix(mtrx, n, m))
        {
            config_array(mtrx, n, m, array);
            print_array(array, m);
            exit_code = EXIT_SUCCESS;
        }
    }
    return exit_code;
}