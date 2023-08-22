#include "main.h"

int main()
{
    int exit_code = EXIT_FAILURE;
    size_t n, m;
    matrix mtrx;
    int array_of_primes[N_MAX_ROWS * M_MAX_COLUMNS];
    size_t len_array_of_primes = 0;

    if (!input_matrix_sizes(&n, &m))
    {
        printf("Enter the elements of the matrix: \n");
        if (!input_matrix(mtrx, n, m))
        {
            if (!config_matrix(mtrx, n, m, array_of_primes, len_array_of_primes))
            {
                print_matrix(mtrx, n, m);
                exit_code = EXIT_SUCCESS;
            }
        }
    }

    return exit_code;
}