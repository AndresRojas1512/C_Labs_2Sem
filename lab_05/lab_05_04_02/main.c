#include "main.h"

int main(int argc, char *argv[])
{
    product_struct product1, product2;
    int exit_code = controller(argc, argv, &product1, &product2);
    return exit_code;
}
