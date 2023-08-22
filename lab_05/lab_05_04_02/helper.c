#include "helper.h"

void get_file_size(FILE *file, int *filesize)
{
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    *filesize = size / sizeof(product_struct);
}

int validate_file(FILE *file)
{
    int exit_code = EXIT_SUCCESS;
    if (!file)
        exit_code = EXIT_FAILURE;
    else
    {
        int filesize;
        get_file_size(file, &filesize);
        if (filesize == 0)
            exit_code = ERROR_EMPTY_FILE;
        fseek(file, 0, SEEK_SET);
    }
    return exit_code;
}

void get_product_by_pos(FILE *file, int pos, product_struct *product)
{
    fseek(file, pos * sizeof(product_struct), SEEK_SET);
    fread(product, sizeof(product_struct), 1, file);
}

void put_product_by_pos(FILE *file, int pos, product_struct *product)
{
    fseek(file, pos * sizeof(product_struct), SEEK_SET);
    fwrite(product, sizeof(product_struct), 1, file);
}

void copy(FILE *src_file, FILE *dest_file, product_struct *product)
{
    int continue_copying = 1;
    while (continue_copying)
    {
        if (fread(product, sizeof(product_struct), 1, src_file) == 1)
        {
            if (fwrite(product, sizeof(product_struct), 1, dest_file) != 1)
                continue_copying = 0;
        }
        else
            continue_copying = 0;
    }
}