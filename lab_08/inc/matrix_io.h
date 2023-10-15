#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "matrix_mem.h"

int matrix_read(double **matrix, size_t m, size_t n);
int sizes_read(size_t *m, size_t *n);
int matrix_create(double ***matrix, size_t *m, size_t *n);
void matrix_output(double **matrix, size_t m, size_t n);

#endif