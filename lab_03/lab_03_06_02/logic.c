#include "logic.h"

void config_matrix(matrix mtrx, size_t n, size_t m)
{
    int value = 1;
    size_t row, column;
    size_t full_size = n * m;
    for (size_t i = 0; i < full_size; i++)
    {
        row = i % n;
        column = i / n;
        if (column % 2 == 0)
        {
            row = n - 1 - row;
        }
        mtrx[row][m - 1 - column] = value++;
    }
}