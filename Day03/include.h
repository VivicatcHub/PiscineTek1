#ifndef INCLUDE_H
#define INCLUDE_H

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c);

/* --- Task 01 --- */

int my_print_alpha(void);

/* --- Task 02 --- */

int my_print_revalpha(void);

/* --- Task 03 --- */

int my_print_digits(void);

/* --- Task 04 --- */

int assert_int_range(int integer, int min, int max);
int assert_int(int integer);
int my_isneg(int n);

/* --- Task 05 --- */

int my_print_comb(void);

/* --- Task 06 --- */

int my_print_comb2(void);

/* --- Task 07 --- */

char int_to_char(int integer);
int my_put_nbr(int nb);

/* --- Task 09 --- */

int pow(int integer, int power);
int my_print_combn(int n);

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

#define NOERROR 0
#define ERROR -1

#endif /* INCLUDE_H */
