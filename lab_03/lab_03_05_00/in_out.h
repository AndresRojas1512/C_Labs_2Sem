#ifndef IN_OUT_H_05
#define IN_OUT_H_05

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"

int input_matrix_sizes(size_t *n, size_t *m);
int input_matrix(matrix mtrx, size_t n, size_t m);
void print_matrix(matrix mtrx, size_t n, size_t m);

#endif