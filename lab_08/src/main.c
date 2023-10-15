#include <stdio.h>
#include <stdlib.h>
#include "matrix_io.h"
#include "matrix_mem.h"
#include "types_macros.h"
#include "matrix_op.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    double **matrix_a;
    double **matrix_b;
    double **matrix_c;
    size_t m, n;
    size_t p, q;
    size_t r, c;
    size_t rho, gamma;
    size_t count_square_power;
    size_t count_rest;
    exit_code = matrix_create(&matrix_a, &m, &n);
    if (!exit_code)
    {
        puts("\tMatrix A:");
        matrix_output(matrix_a, m, n);
        exit_code = matrix_create(&matrix_b, &p, &q);
        if (!exit_code)
        {
            puts("\tMatrix B:");
            matrix_output(matrix_b, p, q);
            if (m != n) // la matrix a no es cuadrada
                exit_code = form_square_matrix(&matrix_a, &m, &n);
            if (p != q) // la matriz b no es cuadrada
                exit_code = form_square_matrix(&matrix_b, &p, &q);
            if (!exit_code)
            {
                if (m != p) // matrices cuadradas pero no iguales
                    exit_code = prepare_square_matrices(&matrix_a, &m, &n, &matrix_b, &p, &q);
                if (!exit_code)
                {
                    puts("\tFactor A:");
                    matrix_output(matrix_a, m, n);
                    puts("\tFactor B:");
                    matrix_output(matrix_b, p, q);

                    printf("Enter rho: ");
                    scanf("%zu", &rho);
                    calc_mult_times(rho, &count_square_power, &count_rest);
                    printf("Times power: %zu, Times rest: %zu\n", count_square_power, count_rest);
                    exit_code = matrix_power(matrix_a, m, n, &matrix_c, &r, &c, count_square_power, count_rest, rho);
                    puts("\tMatrix A power:");
                    matrix_output(matrix_c, r, c);

                    printf("Enter gamma: ");
                    scanf("%zu", &gamma);
                    calc_mult_times(gamma, &count_square_power, &count_rest);
                    printf("Times power: %zu, Times rest: %zu\n", count_square_power, count_rest);
                    exit_code = matrix_power(matrix_b, p, q, &matrix_c, &r, &c, count_square_power, count_rest, gamma);
                    puts("\tMatrix B power:");
                    matrix_output(matrix_c, r, c);
                }
            }
        }
    }
    return exit_code;
}