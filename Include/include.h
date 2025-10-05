#ifndef INCLUDE
#define INCLUDE

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

/* --------------------------------- **
** ------------- Day03 ------------- **
** --------------------------------- */

/* --- Task 01 --- */
int assert_char(char c);
int my_print_alpha(void);
/* --- Task 02 --- */
int my_print_revalpha(void);
/* --- Task 03 --- */
int my_print_digits(void);
/* --- Task 04 --- */
int assert_int_range(long long int integer, long long int min, long long int max);
int assert_int(long long int integer);
int my_isneg(int n);
/* --- Task 05 --- */
int my_print_comb(void);
/* --- Task 06 --- */
int char_to_int(char c);
int my_print_comb2(void);
/* --- Task 07 --- */
char int_to_char(int integer);
int my_put_nbr(int nb);
/* --- Task 09 --- */
int pow(int integer, int power);
int my_print_combn(int n);
/* --- Defines --- */
#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)
#define NOERROR (0)
#define ERROR (-1)

/* --------------------------------- **
** ------------- Day04 ------------- **
** --------------------------------- */

/* --- Task 01 --- */
void my_swap(int *a, int *b);
/* --- Task 02 --- */
int my_putstr(char const *str);
/* --- Task 03 --- */
int my_strlen(char const *str);
/* --- Task 04 --- */
char *my_evil_str(char *str);
/* --- Task 05 --- */
int is_char_number(char c);
int my_getnbr(char const *str);
/* --- Task 06 --- */
void my_sort_int_array(int *array, int size);
void my_quick_sort_int_array(int *array, int size);
/* --- Defines --- */
#define FALSE (0)
#define TRUE (1)

/* --------------------------------- **
** ------------- Day05 ------------- **
** --------------------------------- */

#include <stdlib.h>
/* --- Task 01 --- */
int my_compute_factorial_it(int nb);
/* --- Task 02 --- */
int my_compute_factorial_rec(int nb);
/* --- Task 03 --- */
int my_compute_power_it(int nb, int p);
/* --- Task 04 --- */
int my_compute_power_rec(int nb, int p);
/* --- Task 05 --- */
int my_compute_square_root(int nb);
/* --- Task 06 --- */
int my_is_prime(int nb);
/* --- Task 07 --- */
int my_find_prime_sup(int nb);
/* --- Task 08 --- */
int count_valid_queens_placements(int n);

/* --------------------------------- **
** ------------- Star  ------------- **
** --------------------------------- */

int max(int a, int b);
int assert_uint(long long integer);
void star(unsigned int size);
/* --- Defines --- */
#define UINT_MAX ((unsigned int)4294967295)

#endif /* INCLUDE */
