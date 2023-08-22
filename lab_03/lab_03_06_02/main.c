#include "main.h"

int main()
{
    int exit_code = EXIT_FAILURE;
    size_t n, m;
    matrix mtrx;
    
    printf("Enter the number of rows: \n");
    if (!input_matrix_size(&n))
    {
        printf("Enter the number of columns: \n");
        if (!input_matrix_size(&m))
        {
            config_matrix(mtrx, n, m);
            print_matrix(mtrx, n, m);
            exit_code = EXIT_SUCCESS;
        }
    }

    return exit_code;
}
