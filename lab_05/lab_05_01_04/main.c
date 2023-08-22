#include "main.h"

int main(void)
{
    FILE *file;
    file = stdin;
    int count;
    int exit_code = EXIT_SUCCESS;
    exit_code = process(file, &count);
    if (exit_code == EXIT_SUCCESS)
        fprintf(stdout, "%d", count);
    return exit_code;
}
