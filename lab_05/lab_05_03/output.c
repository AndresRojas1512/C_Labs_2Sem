#include "output.h"

int print_content(const char *filename)
{
    int exit_code = ERROR_OPENING_FILE;
    FILE *file = fopen(filename, "rb");
    int num;
    if (file)
    {
        exit_code = EXIT_SUCCESS;
        fseek(file, 0, SEEK_END);
        size_t file_size_bytes = ftell(file);
        fseek(file, 0, SEEK_SET);
        if (!(file_size_bytes % sizeof(int)) && file_size_bytes)
        {
            for (size_t i = 0; !exit_code && i < file_size_bytes; i += sizeof(int))
            {
                exit_code = fread(&num, sizeof(int), READ_AMOUNT, file) != READ_AMOUNT;
                fprintf(stdout, "%d ", num);
            }
        }
        else
            exit_code = ERROR_READING_FILE;
        fclose(file);
    }
    
    return exit_code;
}
