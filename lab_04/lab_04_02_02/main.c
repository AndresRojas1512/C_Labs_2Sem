#include "main.h"

int main()
{
    int exit_code = EXIT_SUCCESS;
    char string_01[STRING_MAX_LEN], string_02[STRING_MAX_LEN];
    char words_string_01[WORDS_MAX_NUM][WORD_MAX_LEN], words_string_02[WORDS_MAX_NUM][WORD_MAX_LEN];
    size_t string_len_01, string_len_02;
    size_t num_words_01, num_words_02;
    if (!read_line(string_01, &string_len_01) && !read_line(string_02, &string_len_02))
    {
        if (!get_words(string_01, words_string_01, string_len_01, &num_words_01) && !get_words(string_02, words_string_02, string_len_02, &num_words_02))
            logic_output(words_string_01, words_string_02, num_words_01, num_words_02);
    }
    else
        exit_code = EXIT_FAILURE;
    return exit_code;
}
