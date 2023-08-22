#include "logic.h"

int ends_with_five(int x)
{
    return abs(x) % 10 == 5;
}

int find_element_under_antidiag(matrix mtrx, size_t n, size_t m, int *biggest)
{
    int exit_code = EXIT_FAILURE;
    *biggest = INT_MIN;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = n - i; j < m; j++)
        {
            if (ends_with_five(mtrx[i][j]) && (mtrx[i][j] > *biggest))
            {
                *biggest = mtrx[i][j];
                exit_code = EXIT_SUCCESS;
            }
        }
    }
    return exit_code;
}