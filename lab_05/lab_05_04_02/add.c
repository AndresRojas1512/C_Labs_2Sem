#include "add.h"

int ask_product_info(product_struct *product)
{
    int exit_code = EXIT_FAILURE;
    int valid_data = 0;
    if (scanf("%s", product->name))
        valid_data++;
    if (scanf("%s", product->producer))
        valid_data++;
    if (scanf("%u", &(product->price)))
        valid_data++;
    if (scanf("%u", &(product->stock)))
        valid_data++;
    if (valid_data == 4)
        exit_code = EXIT_SUCCESS;
    return exit_code;
}

void add_product_to_file(FILE *file, product_struct *new_product, product_struct *temp_product)
{
    int filesize;
    get_file_size(file, &filesize);
    if (filesize == 0)
        put_product_by_pos(file, 0, new_product);
    else 
    {
        int i = filesize - 1;
        int flag = 1;
        while (i >= 0 && flag)
        {
            get_product_by_pos(file, i, temp_product);
            if (temp_product->price < new_product->price || (temp_product->price == new_product->price && temp_product->stock < new_product->stock))
            {
                put_product_by_pos(file, i + 1, temp_product);
                i--;
            }
            else
            {
                put_product_by_pos(file, i + 1, new_product);
                flag = 0;
            }
        }
        if (flag)
            put_product_by_pos(file, 0, new_product);
    }
}
