#include "logic.h"

int split(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter)
{
    int exit_code = EXIT_SUCCESS;
    char seps[] = " ,;:-.!?";
    char *current_word = strtok(str, seps);
    while ((current_word != NULL) && exit_code == EXIT_SUCCESS)
    {
        if (strlen(current_word) > WORD_MAX_LEN)
            exit_code = EXIT_WORD_LONG;
        strcpy(words_from_str[(*word_counter)++], current_word);
        current_word = strtok(NULL, seps);
    }
    if (*word_counter == 0)
        exit_code = EXIT_NO_WORDS;
    return exit_code;
}

void delete_words(char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter)
{
    char *last_element = words_from_str[*word_counter - 1];
    int shift = 0;
    for (size_t i = 0; i < *word_counter; i++)
    {
        if (strcmp(words_from_str[i], last_element) == 0)
            shift++;
        else if (shift > 0)
            strcpy(words_from_str[i - shift], words_from_str[i]);
    }
    *word_counter -= shift;
}

void delete_letter(char *word, char first_letter, int equals_first)
{
    if (equals_first)
        first_letter = word[0];
    for (size_t i = strlen(word) - 1; i > 0; i--)
    {
        if (word[i] == first_letter)
        {
            for (size_t j = i + 1; j <= strlen(word); j++)
                word[j - 1] = word[j];
        }
    }
}

int form_result_string(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter)
{
    int exit_code = EXIT_SUCCESS;
    delete_words(words_from_str, word_counter);
    for (int i = *word_counter - 1; i >= 0 && exit_code == EXIT_SUCCESS; i--)
    {
        delete_letter(words_from_str[i], '\0', 1);
        if (strlen(words_from_str[i]) > WORD_MAX_LEN)
            exit_code = EXIT_WORD_LONG;
        strcat(str, words_from_str[i]);
        strcat(str, " ");
    }
    if (strlen(str) == 0)
        exit_code = EXIT_EMPTY_STRING;
    else
    {
        str[strlen(str) - 1] = '\0';
        if (strlen(str) > STRING_MAX_LEN)
            exit_code = EXIT_LONG_STRING;
    }
    return exit_code;
}

int process_string(char *str, char words_from_str[WORDS_MAX_NUM][STRING_MAX_LEN], size_t *word_counter, char *result_str)
{
    int exit_code = EXIT_SUCCESS;
    exit_code = split(str, words_from_str, word_counter);
    if (!exit_code)
        exit_code = form_result_string(result_str, words_from_str, word_counter);
    return exit_code;
}
