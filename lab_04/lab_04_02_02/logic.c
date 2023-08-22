#include "logic.h"

int is_word_divider(char c)
{
    const char *word_dividers = " ,:;-.!?";
    return strchr(word_dividers, c) != NULL;
}

int get_words(char *str, char words_from_str[WORDS_MAX_NUM][WORD_MAX_LEN], size_t str_len, size_t *num_words)
{
    size_t word_index = 0;
    size_t char_index = 0;
    int exit_code = 0;
    int is_previous_divider = 1;
    for (size_t i = 0; i < str_len && !exit_code; i++)
    {
        if (!is_word_divider(str[i]))
        {
            if (char_index < WORD_MAX_LEN && !exit_code)
            {
                words_from_str[word_index][char_index++] = str[i];
                is_previous_divider = 0;
            }
            else
                exit_code = EXIT_WORD_LONG;
        }
        else if (!is_previous_divider)
        {
            words_from_str[word_index][char_index] = '\0';
            word_index++;
            char_index = 0;
            is_previous_divider = 1;
            if (word_index > WORDS_MAX_NUM)
                exit_code = EXIT_FAILURE;
        }
    }
    if (!is_previous_divider)
    {
        words_from_str[word_index][char_index] = '\0';
        word_index++;
    }
    *num_words = word_index;
    return exit_code;
}
