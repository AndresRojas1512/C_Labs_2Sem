#include "creation.h"

int create_and_fill(const char *filename)
{
    FILE *file;
    int exit_code = EXIT_SUCCESS;
    file = fopen(filename, "wb");
    if (file == NULL)
    {
        exit_code = ERROR_OPENING_FILE;
    }
    else
    {
        srand((unsigned int)time(NULL));
        int amount = rand() % RANDOM_NUMBER_AMOUNT;
        for (int i = 0; i < amount; i++)
        {
            int random_num = rand() % RANDOM_NUMBER_LIMIT;
            fwrite(&random_num, sizeof(int), 1, file);
        }
        fclose(file);
    }
    return exit_code;
}