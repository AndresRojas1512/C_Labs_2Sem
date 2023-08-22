#ifndef TYPES_MACROS_H
#define TYPES_MACROS_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE_NAME 31
#define MAX_SIZE_PRODUCER 16
#define ERROR_KEYS 53
#define ERROR_EMPTY_FILE 2
#define ERROR_OPENING_SRCFILE 3
#define ERROR_DAMAGED_FILE 4
#define ERROR_EMPTY_FILTER 5
#define ERROR_FILTER_EMPTY 14
#define MIN_ARGS_AMOUNT 3
#define MAX_ARGS_AMOUNT 4

typedef struct
{
    char name[MAX_SIZE_NAME];
    char producer[MAX_SIZE_PRODUCER];
    unsigned int price;
    unsigned int stock;
} product_struct;

#endif
