#include "logic.h"

int sum_of_digits(int num)
{
    int sum = 0;
    num = abs(num);
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int check_is_odd(int num)
{
    int is_odd = 0;
    if (sum_of_digits(num) % 2 == 1)
    {
        is_odd = 1;
    }
    return is_odd;
}

int insertion_algorithm(matrix mtrx, size_t n, size_t m)
{
    size_t new_n = n;
    for (size_t i = 0; i < new_n; i++)
    {
        int count = 0;
        for (size_t j = 0; j < m; j++)
        {
            if (check_is_odd(mtrx[i][j]))
            {
                count++;
            }
        }
        if (count >= 2)
        {
            for (size_t k = new_n; k > i; k--)
            {
                for (size_t j = 0; j < m; j++)
                {
                    mtrx[k][j] = mtrx[k - 1][j];
                }
            }
            for (size_t j = 0; j < m; j++)
            {
                mtrx[i][j] = -1;
            }
            new_n++;
            i++;
        }
    }
    return new_n;
}