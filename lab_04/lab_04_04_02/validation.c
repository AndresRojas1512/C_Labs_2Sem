#include "validation.h"

int check_leap_year(int year);
int validate_month(char *mont_str);
int validate_day(int day, int month, int year);
int validate_year(int year);

int check_leap_year(int year)
{
    return (year % CHECK_LEAP_1 == 0 || (year % CHECK_LEAP_2 != 0 && year % CHECK_LEAP_3 == 0));
}

int my_strcasecmp(const char *s1, const char *s2)
{
    int code = 0;
    for (int i = 0; s1[i] && s2[i] && !code; i++)
        code = tolower(s1[i]) != tolower(s2[i]);
    return code;
}

int validate_month(char *mont_str)
{
    char months[NUM_OF_MONTHS][STRING_MAX_LEN] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
    int month = 0;
    for (int i = 0; i < NUM_OF_MONTHS && !month; i++)
        if (!my_strcasecmp(mont_str, months[i]) && strlen(mont_str) == strlen(months[i]))
            month = i + 1;
    return month;
}

int validate_day(int day, int month, int year)
{
    int valid;
    if (month == ID_FEBRUARY)
    {
        if (day == LEAP_YEAR_DAYS)
            valid = check_leap_year(year);
        else if (MIN_MONTH_DAYS <= day && day <= STD_FEBRUARY_DAYS)
            valid = 1;
        else
            valid = 0;
    }
    else if (day == MAX_MONTH_DAYS)
    {
        valid = month != ID_APRIL && month != ID_JUNE && month != ID_SEPTEMBER && month != ID_NOVEMBER;
    }
    else if (day > MAX_MONTH_DAYS || day < MIN_MONTH_DAYS)
    {
        valid = 0;
    }
    else
        valid = 1;
    return valid;
}

int validate_year(int year)
{
    return year >= 1;
}

int check_dates(char words_array[WORDS_MAX_AMOUNT][STRING_MAX_LEN], int words_count)
{
    int found = 0;
    if (words_count == NUM_DATE_ELEMENTS && (words_array[2][0] != '+' && words_array[2][0] != '-'))
    {
        char *end;
        int year = strtol(words_array[2], &end, 10);
        if (!(*end) && validate_year(year))
        {
            int month = validate_month(words_array[1]);
            if (month && (words_array[0][0] != '+' && words_array[0][0] != '-'))
            {
                int day = strtol(words_array[0], &end, 10);
                if (!(*end) && validate_day(day, month, year))
                {
                    found = 1;
                }
            }
        }
    }
    return found;
}

int validate_date(char *str, char words_array[WORDS_MAX_AMOUNT][STRING_MAX_LEN], size_t *words_count, int *valid_date_found)
{
    *valid_date_found = 0;
    int exit_code = EXIT_SUCCESS;
    if (split(str, words_array, words_count))
        *valid_date_found = 0;
    else
        *valid_date_found = check_dates(words_array, *words_count);
    return exit_code;
}