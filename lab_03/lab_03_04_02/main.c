#include "main.h"

int main()
{
    int exit_code = EXIT_FAILURE;
    size_t n, m;
    matrix mtrx;
    int biggest;
    
    if (!input_matrix_sizes(&n, &m))
    {
        printf("Enter the elements of the matrix: \n");
        if (!input_matrix(mtrx, n, m))
        {
            if (!find_element_under_antidiag(mtrx, n, m, &biggest))
            {
                printf("%d", biggest);
                exit_code = EXIT_SUCCESS;
            }
        }
    }

    return exit_code; 
}