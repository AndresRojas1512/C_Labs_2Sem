#ifndef STRING_WORK_H
#define STRING_WORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
int read_line(char *str);
int split(char *str, char words_from_str[WORDS_MAX_AMOUNT][STRING_MAX_LEN], size_t *word_counter);
#endif
