#ifndef MATRIX_OP
#define MATRIX_OP

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types_macros.h"
#include "matrix_io.h"

int form_square_matrix(double ***matrix, size_t *m, size_t *n);
void find_max(double **matrix, size_t m, size_t n, size_t *col_index, size_t *row_index);
int delete_column(double **matrix, size_t m, size_t *n, size_t col_index);
int delete_row(double ***matrix, size_t *m, size_t row_index);

int add_row(double ***matrix, size_t *m, size_t n);
double calc_column_mean(double **matrix, size_t m, size_t col_index);
int add_colum(double **matrix, size_t m, size_t *n);
double calc_row_min(double **matrix, size_t n, size_t row_index);
int prepare_square_matrices(double ***matrix_a, size_t *m, size_t *n, double ***matrix_b, size_t *p, size_t *q);

void matrix_multiply(double **matrix_a, size_t m, size_t n, double **matrix_b, size_t p, size_t q, double **matrix_c, size_t *r, size_t *c);
void matrix_square_copy(double **matrix_dst, double **matrix_src, size_t m, size_t n);
void calc_mult_times(size_t rho, size_t *count_square_power, size_t *count_rest);
int matrix_power(double **matrix_m, size_t m, size_t n, double ***matrix_r, size_t *r, size_t *c, size_t count_square_power, size_t count_rest, size_t rho);
void matrix_entity(double **matrix, size_t m, size_t n);


#endif