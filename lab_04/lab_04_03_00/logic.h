#ifndef LOGIC_H
#define LOGIC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

int split(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter);
void delete_words(char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter);
void delete_letter(char *word, char first_letter, int equals_first);
int form_result_string(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter);
int process_string(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter, char *result_str);

#endif