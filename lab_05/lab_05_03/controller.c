#include "controller.h"

int controller(int argc, char *argv[])
{
    int exit_code = EXIT_SUCCESS;
    if (argc == ARGS_NUM && !strcmp(argv[1], "c"))
        exit_code = create_and_fill(argv[2]);
    else if (argc == ARGS_NUM && !strcmp(argv[1], "p"))
        exit_code = print_content(argv[2]);
    else if (argc == ARGS_NUM && !strcmp(argv[1], "s"))
        exit_code = sort_numbers_in_file(argv[2]);
    else
        exit_code = ERROR_ARGS_NUM;
    return exit_code;
}
