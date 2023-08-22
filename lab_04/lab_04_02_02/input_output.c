#include "input_output.h"

int read_line(char *str, size_t *string_len)
{
    int exit_code = EXIT_SUCCESS;
    if (fgets(str, STRING_MAX_LEN + 2, stdin) == NULL)
        exit_code = EXIT_UB; 
    else
    {
        *string_len = strlen(str);
        if (*str == '\n')
            exit_code = EXIT_EMPTY_STRING;
        else if (*string_len == (STRING_MAX_LEN + 1) && str[*string_len - 1] != '\n')
            exit_code = EXIT_ERROR_BUFFER;
        str[*string_len - 1] = '\0';
    }
    return exit_code;
}

int check_repeated_word(char *word, char words_from_str[WORDS_MAX_NUM][WORD_MAX_LEN], size_t num_words)
{
    int is_present = 0;
    for (size_t i = 0; i < num_words; i++)
    {
        if (strcmp(words_from_str[i], word) == 0)
            is_present = 1;
    }
    return is_present;
}

void logic_output(char words_string_01[WORDS_MAX_NUM][WORD_MAX_LEN], char words_string_02[WORDS_MAX_NUM][WORD_MAX_LEN], size_t num_words_01, size_t num_words_02)
{
    printf("Result: ");
    int found;
    for (size_t i = 0; i < num_words_01; i++)
    {
        if (i > 0 && check_repeated_word(words_string_01[i], words_string_01, i))
            continue;
        else
        {
            found = 0;
            for (size_t j = 0; j < num_words_02; j++)
            {
                if (strcmp(words_string_01[i], words_string_02[j]) == 0)
                    found = 1;
            }
            if (found)
                printf("%s yes\n", words_string_01[i]);
            else
                printf("%s no\n", words_string_01[i]);
        }
    }
}

void print_words(char words_from_string[WORDS_MAX_NUM][WORD_MAX_LEN], size_t num_words)
{
    for (size_t i = 0; i < num_words; i++)
        printf("%s\n", words_from_string[i]);
}