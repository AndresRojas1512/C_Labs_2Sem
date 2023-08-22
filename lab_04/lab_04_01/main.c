#include "main.h"

int main()
{
    int exit_code = EXIT_SUCCESS;
    int errors = 0;
    char str1[TEST_CASES][W_MAX_LEN] = {
        "apple", 
        "banana", 
        "cherry", 
        "date", 
        "pineaapple", 
        "watemelon", 
        ""
    };
    char str2[TEST_CASES][W_MAX_LEN] = {
        "plum", 
        "mandarin", 
        "raspberry", 
        "strawberry", 
        "mango", 
        "lemon", 
        ""
    };
    int chars[TEST_CASES] = { 'a', 'b', 'c', 'o', 'z', '\0', 'n' };

    for (size_t i = 0; i < TEST_CASES; i++)
    {
        if (strpbrk(str1[i], str2[i]) != my_strpbrk(str1[i], str2[i]))
        {
            errors++;
        }
        if (strspn(str1[i], str2[i]) != my_strspn(str1[i], str2[i]))
        {
            errors++;
        }
        if (strcspn(str1[i], str2[i]) != my_strcspn(str1[i], str2[i]))
        {
            errors++;
        }
        if (strchr(str1[i], chars[i]) != my_strchr(str1[i], chars[i]))
        {
            errors++;
        }
        if (strchr(str2[i], chars[i]) != my_strchr(str2[i], chars[i]))
        {
            errors++;
        }
        if (strrchr(str1[i], chars[i]) != my_strrchr(str1[i], chars[i]))
        {
            errors++;
        }
        if (strrchr(str2[i], chars[i]) != my_strrchr(str2[i], chars[i]))
        {
            errors++;
        }
    }
    printf("%d\n", errors);
    return exit_code;
}

