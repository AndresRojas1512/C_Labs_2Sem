#include "main.h"

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    char str[STRING_MAX_LEN];
    size_t words_count;
    int valid_date_found = 0;
    char words_array[WORDS_MAX_AMOUNT][STRING_MAX_LEN];
    exit_code = read_line(str);
    if (!exit_code)
    {
        exit_code = validate_date(str, words_array, &words_count, &valid_date_found);
        printf(valid_date_found ? "YES\n" : "NO\n");
    }
    return exit_code;
}
