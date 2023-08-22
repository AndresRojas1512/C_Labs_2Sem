#include "controller.h"

int controller(int argc, char *argv[], product_struct *product1, product_struct *product2)
{
    int exit_code = EXIT_SUCCESS;
    if (argc < MIN_ARGS_AMOUNT || argc > MAX_ARGS_AMOUNT)
        exit_code = ERROR_KEYS;
    else
    {
        char *command = argv[1];
        if (strcmp(command, "sb") == 0)
        {
            if (argc != MAX_ARGS_AMOUNT)
                exit_code = ERROR_KEYS;
            else
            {
                FILE *src_file = fopen(argv[2], "rb");
                if (validate_file(src_file) != EXIT_SUCCESS)
                    exit_code = ERROR_OPENING_SRCFILE;
                else
                {
                    exit_code = EXIT_SUCCESS;
                    FILE *dest_file = fopen(argv[3], "wb+");
                    copy(src_file, dest_file, product1);
                    sort_products_in_file(dest_file, product1, product2);
                    fclose(src_file);
                    fclose(dest_file);
                }
            }
        }
        else if (strcmp(command, "fb") == 0)
        {
            int counter = 0;
            if (argc != MAX_ARGS_AMOUNT)
                exit_code = ERROR_KEYS;
            else
            {
                FILE *file = fopen(argv[2], "rb");
                if (validate_file(file) != EXIT_SUCCESS)
                    exit_code = ERROR_OPENING_SRCFILE;
                else
                {
                    print_products_with_suffix(file, argv[3], product1, &counter);
                    if (counter == 0)
                        exit_code = ERROR_FILTER_EMPTY;
                    fclose(file);
                }
            }
            return exit_code;
        }
        else if (strcmp(command, "ab") == 0)
        {
            if (argc != MIN_ARGS_AMOUNT)
                exit_code = ERROR_KEYS;
            else
            {
                FILE *file = fopen(argv[2], "rb+");
                if (validate_file(file) == EXIT_FAILURE)
                    exit_code = ERROR_OPENING_SRCFILE;
                else
                {
                    memset(product1, 0, sizeof(product_struct));
                    if (ask_product_info(product1) != EXIT_SUCCESS)
                        exit_code = EXIT_FAILURE;
                    else
                    {
                        add_product_to_file(file, product1, product2);
                        exit_code = EXIT_SUCCESS;
                    }
                }
            }
        }
        else
            exit_code = ERROR_KEYS;
    }
    return exit_code;
}
