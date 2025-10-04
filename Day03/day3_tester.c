#include "include.h"

int main(void)
{
    // my_putchar
    printf("my_putchar:\n");
    my_putchar('A');
    my_putchar('\n');
    my_putchar('5');

    // my_print_alpha
    printf("\n\nmy_print_alpha:\n");
    my_print_alpha();

    // my_print_revalpha
    printf("\n\nmy_print_revalpha:\n");
    my_print_revalpha();

    // my_print_digits
    printf("\n\nmy_print_digits:\n");
    my_print_digits();

    // my_isneg
    printf("\n\nmy_isneg:\n");
    printf(":-5\n", my_isneg(-5));
    printf(": 0\n", my_isneg(0));
    printf(": 5\n", my_isneg(5));

    // my_print_comb
    printf("\n\nmy_print_comb:\n");
    my_print_comb();

    // my_print_comb2
    printf("\n\nmy_print_comb2:\n");
    my_print_comb2();

    // int_to_char
    printf("\n\nint_to_char:\n");
    for (int i = -1; i < 10; i++)
        printf("%d -> '%c'\n", i, int_to_char(i));

    // my_put_nbr
    printf("\n\nmy_put_nbr:\n");
    my_put_nbr(INT_MIN);
    my_putchar('\n');
    my_put_nbr(-123456);
    my_putchar('\n');
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(7);
    my_putchar('\n');
    my_put_nbr(69);
    my_putchar('\n');
    my_put_nbr(123456);
    my_putchar('\n');
    my_put_nbr(INT_MAX);
    my_putchar('\n');

    // pow
    printf("\n\npow:\n");
    printf("2^0  = %d\n", pow(2, 0));
    printf("2^1  = %d\n", pow(2, 1));
    printf("2^2  = %d\n", pow(2, 2));
    printf("2^3  = %d\n", pow(2, 3));
    printf("5^3  = %d\n", pow(5, 3));
    printf("10^5 = %d\n", pow(10, 5));

    // my_print_combn
    printf("\n\nmy_print_combn:");
    printf("\n- 1 :\n");
    my_print_combn(1);
    printf("\n- 2 :\n");
    my_print_combn(2);
    printf("\n- 3 :\n");
    my_print_combn(3);
    printf("\n- 4 :\n");
    my_print_combn(4);

    return 0;
}
