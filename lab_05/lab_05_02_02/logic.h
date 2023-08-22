#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include "macros.h"
int calc_variance(FILE *file, double average, double *variance);
int calc_average(FILE *file, double *average);
int validate_args(int argc);

#endif