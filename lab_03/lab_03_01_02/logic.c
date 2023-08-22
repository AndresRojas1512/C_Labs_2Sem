#include "logic.h"

int check_negative_product(int x, int y);
int check_has_one_row(size_t n);

int check_negative_product(int x, int y)
{
    return x * y < 0;
}

int check_has_one_row(size_t n)
{
    int has_one_row = 0;
    if (n == 1)
    {
        has_one_row = 1;
    }
    return has_one_row;
}

void config_array(matrix mtrx, size_t n, size_t m, int *array)
{
    for (size_t j = 0; j < m; j++)
    {
        if (check_has_one_row(n))
        {
            array[j] = 0;
        }
        else
        {
            array[j] = 1;
            for (size_t i = 0; (i < n - 1) && array[j]; i++)
            {
                array[j] = check_negative_product(mtrx[i][j], mtrx[i + 1][j]);
            }
        }
    }
}