#ifndef MATRIX_MEM_H
#define MATRIX_MEM_H

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"

double **matrix_alloc(size_t m, size_t n);
void matrix_free(double **matrix, size_t m);

#endif