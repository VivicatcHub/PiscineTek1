#include "include.h"

/* ----- Task 01 ----- */

/// @brief Swap the values of two integers
/// @param a Pointer to the first integer
/// @param b Pointer to the second integer
/// @return void
void my_swap(int *a, int *b)
{
    // Assert inputs
    assert_int(*a);
    assert_int(*b);

    // Main code
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ----- Task 02 ----- */

/// @brief Print a string to the standard output
/// @param str The string to print
/// @return NOERROR on success, ERROR if str is NULL
int my_putstr(char const *str)
{
    if (str == NULL)
        return ERROR;
    for (int index = 0; str[index] != '\0'; index++)
        my_putchar(str[index]);
    return NOERROR;
}

/* ----- Task 03 ----- */

/// @brief Get the length of a string
/// @param str The string to measure
/// @return The length of the string, or ERROR if str is NULL
int my_strlen(char const *str)
{
    if (str == NULL)
        return 0;
    int size = 0;
    for (; str[size] != '\0'; size++)
        ;
    return size;
}

/* ----- Task 04 ----- */

/// @brief Reverse a string in place
/// @param str The string to reverse
/// @return A pointer to the reversed string, or NULL if str is NULL
char *my_evil_str(char *str)
{
    if (str == NULL)
        return NULL;
    int size = my_strlen(str);
    for (int index = 0; index < size / 2; index++)
    {
        char temp = str[index];
        str[index] = str[size - index - 1];
        str[size - index - 1] = temp;
    }
    return str;
}

/* ----- Task 05 ----- */

/// @brief Check if a character is a digit
/// @param c The character to check
/// @return 1 if c is a digit, 0 otherwise
int is_char_number(char c)
{
    return (c >= '0' && c <= '9');
}

/// Private function for my_getnbr
int is_char_to_stop(char c)
{
    return !(is_char_number(c) || c == '-' || c == '+');
}

/// @brief Convert a string to an integer
/// @param str The string to convert
/// @return The converted integer, or 0 if str is NULL
int my_getnbr(char const *str)
{
    if (str == NULL)
        return 0;
    long long result = 0;
    int sign = 1;
    for (int index = 0; str[index] != '\0'; index++)
    {
        char c = str[index];
        if (c == '-')
            sign *= -1;
        if (is_char_number(c))
        {
            if (assert_int(result * 10 + char_to_int(c)) == ERROR)
                return 0;
            result = result * 10 + char_to_int(c);
        }
        if (is_char_to_stop(c))
            break;
    }
    if (assert_int(result * sign) == ERROR)
        return 0;
    return result * sign;
}

/* ----- Task 06 ----- */

/// @brief Sort an array of integers in ascending order
/// @param array The array to sort
/// @param size The size of the array
/// @return void
void my_sort_int_array(int *array, int size)
{
    while (size > 1)
    {
        int new_n = 0;
        for (int i = 1; i < size; i++)
            if (array[i - 1] > array[i])
            {
                my_swap(&array[i - 1], &array[i]);
                new_n = i;
            }
        size = new_n;
    }
}

/// Private function for my_quick_sort_int_array
int part(int *array, int first, int last, int pivot)
{
    my_swap(&array[pivot], &array[last]);
    int j = first;
    for (int i = first; i < last; i++)
    {
        if (array[i] <= array[last])
        {
            my_swap(&array[i], &array[j]);
            j++;
        }
    }
    my_swap(&array[last], &array[j]);
    return j;
}

/// Private function for my_quick_sort_int_array
void quick_sort(int *array, int first, int last)
{
    if (first < last)
    {
        int pivot = (last + 1) / 2;
        pivot = part(array, first, last, pivot);
        quick_sort(array, first, pivot - 1);
        quick_sort(array, pivot + 1, last);
    }
}

/// @brief Sort an array of integers in ascending order using quicksort
/// @param array The array to sort
/// @param size The size of the array
/// @return void
void my_quick_sort_int_array(int *array, int size)
{
    quick_sort(array, 0, size - 1);
}