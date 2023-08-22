#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "macros.h"
#include "string_work.h"
int check_dates(char words_array[WORDS_MAX_AMOUNT][STRING_MAX_LEN], int words_count);
int validate_date(char *str, char words_array[WORDS_MAX_AMOUNT][STRING_MAX_LEN], size_t *words_count, int *valid_date_found);
#endif
