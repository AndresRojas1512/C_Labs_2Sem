#include "main.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    char str[STRING_MAX_LEN];
    char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN];
    char result_str[STRING_MAX_LEN] = "";
    size_t word_counter = 0;
    exit_code = read_line(str);
    if (!exit_code)
    {
        exit_code = process_string(str, words_from_str, &word_counter, result_str);
        if (!exit_code)
            printf("Result: %s\n", result_str);
    }
    return exit_code;
}
