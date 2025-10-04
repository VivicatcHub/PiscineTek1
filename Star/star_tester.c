#include "include.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        my_putstr("Usage: ./test_piscine <size>\n");
        return ERROR;
    }
    unsigned int size = my_getnbr(argv[1]);
    star(size);
    return NOERROR;
}
