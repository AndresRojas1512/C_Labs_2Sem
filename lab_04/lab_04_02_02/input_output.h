#ifndef STRINGWORK_H
#define STRINGWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
int read_line(char *str, size_t *string_len);
void logic_output(char words_string_01[WORDS_MAX_NUM][WORD_MAX_LEN], char words_string_02[WORDS_MAX_NUM][WORD_MAX_LEN], size_t num_words_01, size_t num_words_02);
void print_words(char words_from_string[WORDS_MAX_NUM][WORD_MAX_LEN], size_t num_words);
#endif