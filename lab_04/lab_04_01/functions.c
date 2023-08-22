#include "functions.h"

char *my_strpbrk(char *str1, char *str2)
{
    char *return_value = 0;
    char *temp;
    while ((*str1 != '\0') && (return_value == 0))
    {
        temp = str2;
        while ((*temp != '\0') && (return_value == 0))
        {
            if (*str1 == *temp)
            {
                return_value = str1;
            }
            temp++;
        }
        str1++;
    }
    return return_value;
}

size_t my_strspn(char *str1, char *str2)
{
    size_t length = 0;
    int found = 1;
    while (*str1 != '\0' && found)
    {
        found = 0;
        char *tmp = str2;
        while (*tmp != '\0' && !found)
        {
            if (*tmp == *str1)
            {
                found = 1;
            }
            tmp++;
        }
        if (found)
        {
            length++;
            str1++;
        }
    }
    return length;
}

size_t my_strcspn(char *str1, char *str2)
{
    size_t length = 0;
    int found = 0;
    while (*str1 != '\0' && !found)
    {
        char *tmp = str2;
        while (*tmp != '\0' && !found)
        {
            if (*tmp == *str1)
            {
                found = 1;
            }
            tmp++;
        }
        if (!found)
        {
            length++;
            str1++;
        }
    }
    return length;
}

char *my_strchr(char *str, int c)
{
    char *result = NULL;
    int found = 0;
    while (*str != '\0' && !found)
    {
        if (*str == c)
        {
            result = str;
            found = 1;
        }
        str++;
    }
    if (*str == c)
    {
        result = str;
    }
    return result;
}

char *my_strrchr(char *str, int c)
{
    char *result = NULL;
    while (*str != '\0')
    {
        if (*str == c)
        {
            result = str;
        }
        str++;
    }
    if (*str == c)
    {
        result = str;
    }
    return result;
}