#include "main.h"

int main()
{
    int exit_code = EXIT_FAILURE;
    size_t n, m;
    matrix mtrx;
    
    if (!input_matrix_sizes(&n, &m))
    {
        printf("Enter the elements of the matrix: \n");
        if (!input_matrix(mtrx, n, m))
        {
            n = insertion_algorithm(mtrx, n, m);
            print_matrix(mtrx, n, m);
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}












