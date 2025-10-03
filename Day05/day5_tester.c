#include "include.h"

int main(void)
{
    // my_compute_factorial_it
    printf("my_compute_factorial_it:\n");
    printf("Factorial of %d  is %d\n", 5, my_compute_factorial_it(5));
    printf("Factorial of %d  is %d\n", 7, my_compute_factorial_it(7));
    printf("Factorial of %d is %d\n", 19, my_compute_factorial_it(19));

    // my_compute_factorial_rec
    printf("\nmy_compute_factorial_rec:\n");
    printf("Factorial of %d  is %d\n", 5, my_compute_factorial_rec(5));
    printf("Factorial of %d  is %d\n", 7, my_compute_factorial_rec(7));
    printf("Factorial of %d is %d\n", 19, my_compute_factorial_rec(19));

    // my_compute_power_it
    printf("\nmy_compute_power_it:\n");
    printf("%d to the power of %d is %d\n", 2, 3, my_compute_power_it(2, 3));
    printf("%d to the power of %d is %d\n", 5, 4, my_compute_power_it(5, 4));
    printf("%d to the power of %d is %d\n", 10, 5, my_compute_power_it(10, 5));

    // my_compute_power_rec
    printf("\nmy_compute_power_rec:\n");
    printf("%d to the power of %d is %d\n", 2, 3, my_compute_power_rec(2, 3));
    printf("%d to the power of %d is %d\n", 5, 4, my_compute_power_rec(5, 4));
    printf("%d to the power of %d is %d\n", 10, 5, my_compute_power_rec(10, 5));

    // my_compute_square_root
    printf("\nmy_compute_square_root:\n");
    printf("Square root of %d is %d\n", 9, my_compute_square_root(9));
    printf("Square root of %d is %d\n", 16, my_compute_square_root(16));
    printf("Square root of %d is %d\n", 25, my_compute_square_root(25));
    printf("Square root of %d is %d\n", 20, my_compute_square_root(20));

    // my_is_prime
    printf("\nmy_is_prime:\n");
    printf("%d is prime: %d\n", 7, my_is_prime(7));
    printf("%d is prime: %d\n", 10, my_is_prime(10));
    printf("%d is prime: %d\n", 13, my_is_prime(13));
    printf("%d is prime: %d\n", 25, my_is_prime(25));
    printf("%d is prime: %d\n", 0, my_is_prime(0));
    printf("%d is prime: %d\n", 1, my_is_prime(1));

    // my_find_prime_sup
    printf("\nmy_find_prime_sup:\n");
    printf("Next prime after %d is %d\n", 10, my_find_prime_sup(10));
    printf("Next prime after %d is %d\n", 14, my_find_prime_sup(14));
    printf("Next prime after %d is %d\n", 20, my_find_prime_sup(20));
    printf("Next prime after %d is %d\n", 25, my_find_prime_sup(25));

    // count_valid_queens_placements
    printf("\ncount_valid_queens_placements:\n");
    printf("Number of valid placements for %d queens: %d\n", 1, count_valid_queens_placements(1)); // 1
    printf("Number of valid placements for %d queens: %d\n", 2, count_valid_queens_placements(2)); // 0
    printf("Number of valid placements for %d queens: %d\n", 3, count_valid_queens_placements(3)); // 0
    printf("Number of valid placements for %d queens: %d\n", 4, count_valid_queens_placements(4)); // 2
    printf("Number of valid placements for %d queens: %d\n", 5, count_valid_queens_placements(5)); // 10
    printf("Number of valid placements for %d queens: %d\n", 6, count_valid_queens_placements(6)); // 4
    printf("Number of valid placements for %d queens: %d\n", 7, count_valid_queens_placements(7)); // 40
}