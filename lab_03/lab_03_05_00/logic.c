#include "logic.h"

int check_prime(int num)
{
    int is_prime = 1;
    if (num <= 1)
    {
        is_prime = 0;
    }
    else
    {
        for (int i = 2; i * i <= num && is_prime; i++)
        {
            if (num % i == 0)
            {
                is_prime = 0;
            }
        }
    }
    return is_prime;
}

int get_primes(matrix mtrx, size_t n, size_t m, int *array_of_primes)
{
    size_t len_array_of_primes = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (check_prime(mtrx[i][j]))
            {
                array_of_primes[len_array_of_primes] = mtrx[i][j];
                len_array_of_primes++;
            }
        }
    }
    return len_array_of_primes;
}

int config_matrix(matrix mtrx, size_t n, size_t m, int *array_of_primes, size_t len_array_of_primes)
{
    int exit_code = EXIT_SUCCESS;
    len_array_of_primes = get_primes(mtrx, n, m, array_of_primes);
    if (len_array_of_primes < MINIMUM_SIZE)
    {
        exit_code = EXIT_FAILURE;
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (check_prime(mtrx[i][j]))
                {
                    mtrx[i][j] = array_of_primes[--len_array_of_primes];
                }
            }
        }
    }
    return exit_code;
}
