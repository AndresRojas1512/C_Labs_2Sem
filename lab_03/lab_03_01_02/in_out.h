#ifndef INPUT_OUTPUT_H_01
#define INPUT_OUTPUT_H_01

#include <stdlib.h>
#include <stdio.h>
#include "types_macros.h"

int input_matrix_sizes(size_t *n, size_t *m);
int input_matrix(matrix mtrx, size_t n, size_t m);
void print_array(int *array, size_t m);

#endif