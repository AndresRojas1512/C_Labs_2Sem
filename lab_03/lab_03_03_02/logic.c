#include "logic.h"

int product_of_current_row(int *row, size_t m)
{
    int product = 1;
    for (size_t i = 0; i < m; i++)
    {
        product *= row[i];
    }
    return product;
}

void swap(int *rowa, int *rowb, size_t m)
{
    int tmp;
    for (size_t i = 0; i < m; i++)
    {
        tmp = rowa[i];
        rowa[i] = rowb[i];
        rowb[i] = tmp;
    }
}

void sort_rows(matrix mtrx, size_t n, size_t m)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (product_of_current_row(mtrx[j], m) < product_of_current_row(mtrx[i], m))
            {
                swap(mtrx[j], mtrx[i], m);
            }
        }
    }
}