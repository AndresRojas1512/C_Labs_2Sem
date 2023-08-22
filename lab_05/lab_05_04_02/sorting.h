#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
#include "helper.h"
void swap_products_in_file(FILE *file, int pos1, int pos2, product_struct *product1, product_struct *product2);
void sort_products_in_file(FILE *file, product_struct *product1, product_struct *product2);

#endif