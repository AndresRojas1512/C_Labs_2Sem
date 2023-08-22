#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include "types_macros.h"
void get_file_size(FILE *file, int *filesize);
int validate_file(FILE *file);
void get_product_by_pos(FILE *file, int pos, product_struct *product);
void put_product_by_pos(FILE *file, int pos, product_struct *product);
void copy(FILE *src_file, FILE *dest_file, product_struct *product);
#endif