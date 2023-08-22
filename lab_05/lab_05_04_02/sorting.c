#include "sorting.h"

void swap_products_in_file(FILE *file, int pos1, int pos2, product_struct *product1, product_struct *product2)
{
    get_product_by_pos(file, pos1, product1);
    put_product_by_pos(file, pos2, product2);
    put_product_by_pos(file, pos1, product2);
    put_product_by_pos(file, pos2, product1);
}

void sort_products_in_file(FILE *file, product_struct *product1, product_struct *product2)
{
    int filesize;
    get_file_size(file, &filesize);
    for (int i = 0; i < filesize - 1; i++)
    {
        for (int j = i + 1; j < filesize; j++)
        {
            get_product_by_pos(file, i, product1);
            get_product_by_pos(file, j, product2);
            if (product1->price < product2->price || (product1->price == product2->price && product1->stock < product2->stock))
                swap_products_in_file(file, i, j, product1, product2);
        }
    }
}
