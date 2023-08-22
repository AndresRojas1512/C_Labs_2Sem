#ifndef ADD_INFO_H
#define ADD_INFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "helper.h"
#include "types_macros.h"
int ask_product_info(product_struct *product);
void add_product_to_file(FILE *file, product_struct *new_product, product_struct *temp_product);
#endif
