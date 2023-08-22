#ifndef LOGIC_02_H
#define LOGIC_02_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
int get_words(char *str, char words_from_str[WORDS_MAX_NUM][WORD_MAX_LEN], size_t str_len, size_t *num_words);

#endif