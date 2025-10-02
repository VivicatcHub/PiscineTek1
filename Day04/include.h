#ifndef INCLUDE_DAY05
#define INCLUDE_DAY05

#include <unistd.h>
#include <stdio.h>

#include "../Day03/include.h"

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

#endif /* INCLUDE_DAY05 */