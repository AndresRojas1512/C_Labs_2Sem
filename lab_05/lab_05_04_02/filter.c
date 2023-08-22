#include "filter.h"

int check_ends_with(char *str, char *suffix)
{
    int ends_with = 0;
    if (str && suffix)
    {
        size_t len_str = strlen(str);
        size_t len_suffix = strlen(suffix);
        if (len_suffix > len_str)
        {
            ends_with = 0;
        }
        else
        {
            if (strncmp(str + len_str - len_suffix, suffix, len_suffix) == 0)
            {
                ends_with = 1;
            }
        }
    }
    else
        ends_with = 0;
    return ends_with;
}


void print_product_info(product_struct *product)
{
    printf("%s\n", product->name);
    printf("%s\n", product->producer);
    printf("%u\n", product->price);
    printf("%u\n", product->stock);
}

int print_products_with_suffix(FILE *file, char *suffix, product_struct *product, int *counter)
{
    int exit_code = EXIT_SUCCESS;
    int filesize;
    get_file_size(file, &filesize);
    *counter = 0;
    for (int i = 0; i < filesize; i++)
    {
        get_product_by_pos(file, i, product);
        if (check_ends_with(product->name, suffix))
        {
            (*counter)++;
            print_product_info(product);
        }
    }
    if ((*counter) == 0)
        exit_code = ERROR_EMPTY_FILTER;
    return exit_code;
}