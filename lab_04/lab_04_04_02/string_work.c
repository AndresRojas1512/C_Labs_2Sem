#include "string_work.h"

int read_line(char *str)
{
    int exit_code = EXIT_FAILURE;
    if (fgets(str, STRING_MAX_LEN + 2, stdin) && str[strlen(str) - 1] == '\n')
        exit_code = EXIT_SUCCESS;
    return exit_code;
}

int append_word(const char *word, char array[WORDS_MAX_AMOUNT][STRING_MAX_LEN], size_t *n)
{
    char exit_code = EXIT_SUCCESS;
    if (*n < WORDS_MAX_AMOUNT)
    {
        int i;
        for (i = 0; i < (STRING_MAX_LEN - 1) && word[i]; i++)
            array[*n][i] = word[i];
        array[*n][i] = '\0';
        (*n)++;
    }
    return exit_code;
}

int split(char *str, char words[WORDS_MAX_AMOUNT][STRING_MAX_LEN], size_t *words_count)
{
    *words_count = 0;
    const char *delim = " \t\n";
    if (strrchr(str, '\n') && str[0] != '\n')
    {
        char *token = strtok(str, delim);
        while (token)
            if (!append_word(token, words, words_count))
                token = strtok(NULL, delim);
            else
                token = NULL;
    }
    return *words_count <= 0;
}
