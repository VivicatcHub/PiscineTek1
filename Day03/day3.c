#include "include.h"

/// @brief Check if a character is valid (ASCII)
/// @param c The character to check
/// @return ERROR if the character is invalid, NOERROR otherwise
int assert_char(char c)
{
    if (c < 0)
        return ERROR;
    return NOERROR;
}

/// @brief Write a character to the standard output
/// @param c The character to write
/// @return None
void my_putchar(char c)
{
    // Assert inputs
    if (assert_char(c) == ERROR)
        return;

    // Main code
    write(1, &c, 1);
}

/* ----- Task 01 ----- */

/// @brief Print the lowercase alphabet
/// @param None
/// @return Always NOERROR
int my_print_alpha(void)
{
    for (char letter = 'a'; letter <= 'z'; letter++)
        my_putchar(letter);
    return NOERROR;
}

/* ----- Task 02 ----- */

/// @brief Print the lowercase alphabet in reverse
/// @param None
/// @return Always NOERROR
int my_print_revalpha(void)
{
    for (char letter = 'z'; letter >= 'a'; letter--)
        my_putchar(letter);
    return NOERROR;
}

/* ----- Task 03 ----- */

/// @brief Print the digits
/// @param None
/// @return Always NOERROR
int my_print_digits(void)
{
    for (char digit = '0'; digit <= '9'; digit++)
        my_putchar(digit);
    return NOERROR;
}

/* ----- Task 04 ----- */

/// @brief Check if an integer is within a specific range
/// @param integer The integer to check
/// @param min The minimum value (inclusive)
/// @param max The maximum value (inclusive)
/// @return ERROR if the integer is out of range, NOERROR otherwise
int assert_int_range(long long integer, int min, int max)
{
    if (integer < min || integer > max)
        return ERROR;
    return NOERROR;
}

/// @brief  Check if an integer is within the range of a standard 32-bit signed integer
/// @param integer The integer to check
/// @return ERROR if the integer is out of range, NOERROR otherwise
int assert_int(long long integer)
{
    if (assert_int_range(integer, INT_MIN, INT_MAX) == ERROR)
        return ERROR;
    return NOERROR;
}

/// @brief Print 'N' if the integer is negative, 'P' otherwise
/// @param n The integer to check
/// @return ERROR if the integer is out of range, NOERROR otherwise
int my_isneg(int n)
{
    // Assert inputs
    if (assert_int(n) == ERROR)
        return ERROR;

    // Main code
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return NOERROR;
}

/* ----- Task 05 ----- */

/// @brief Print all combinations of three different digits
/// @param None
/// @return Always NOERROR
int my_print_comb(void)
{
    for (char i = '0'; i <= '7'; i++)
        for (char j = i + 1; j <= '8'; j++)
            for (char k = j + 1; k <= '9'; k++)
            {
                my_putchar(i);
                my_putchar(j);
                my_putchar(k);
                if (i != '7')
                {
                    my_putchar(',');
                    my_putchar(' ');
                }
            }
    return NOERROR;
}

/* ----- Task 06 ----- */

/// @brief Convert a character to its integer value
/// @param c The character to convert
/// @return The integer value of the character
int char_to_int(char c)
{
    // Assert inputs
    if (assert_char(c) == ERROR)
        return ERROR;

    // Main code
    return c - '0';
}

// Private function for my_print_comb2
int has_to_be_displayed(char a, char b, char c, char d)
{
    int first_number = char_to_int(a) * 10 + char_to_int(b);
    int second_number = char_to_int(c) * 10 + char_to_int(d);

    return first_number < second_number;
}

/// @brief Print all combinations of two different digits
/// @param None
/// @return Always NOERROR
int my_print_comb2(void)
{
    for (char a = '0'; a <= '9'; a++)
        for (char b = '0'; b <= '9'; b++)
            for (char c = '0'; c <= '9'; c++)
                for (char d = '0'; d <= '9'; d++)
                    if (has_to_be_displayed(a, b, c, d))
                    {
                        my_putchar(a);
                        my_putchar(b);
                        my_putchar(' ');
                        my_putchar(c);
                        my_putchar(d);
                        if (!(a == '9' && b == '8'))
                        {
                            my_putchar(',');
                            my_putchar(' ');
                        }
                    }
    return NOERROR;
}

/* ----- Task 07 ----- */

/// @brief Convert an integer (0-9) to its character representation
/// @param integer The integer to convert
/// @return The character representation of the integer, or ERROR if out of range
char int_to_char(int integer)
{
    // Assert inputs
    if (assert_int_range(integer, 0, 9))
        return ERROR;

    // Main code
    return integer + '0';
}

/// @brief Print an integer
/// @param nb The integer to print
/// @return Always NOERROR
int my_put_nbr(int nb)
{
    // Assert inputs
    if (assert_int(nb))
        return ERROR;

    // Main code
    if (nb == INT_MIN)
    {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0)
    {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(int_to_char(nb % 10));
    return NOERROR;
}

/* ----- Task 09 ----- */

/// @brief Compute the power of an integer
/// @param integer The base integer
/// @param power The exponent (must be non-negative)
/// @return The result of integer raised to the power, or ERROR if inputs are invalid
int pow(int integer, int power)
{
    // Assert inputs
    if (assert_int(integer))
        return ERROR;
    if (assert_int_range(power, 0, INT_MAX))
        return ERROR;

    // Main code
    int result = 1;

    if (power == 0)
        return result;
    for (int i = 0; i < power; i++)
        result *= integer;
    return result;
}

/// Private function for my_print_combn
int get_max_for_n(int n)
{
    int result = 0;

    for (int i = 1; i < n + 1; i++)
        result += (10 - i) * pow(10, i - 1);
    return result;
}

/// Private function for my_print_combn
void my_print_combn_recursive(int index, int current, int max, int list)
{
    if (index == 0)
    {
        int temp_list = list;
        for (int i = 1; i <= max; i++)
        {
            int value = temp_list / pow(10, max - i);
            my_put_nbr(value);
            temp_list %= pow(10, max - i);
        }
        if (list != get_max_for_n(max))
        {
            my_putchar(',');
            my_putchar(' ');
        }
        return;
    }
    for (int i = current + 1; i < 11 - index; i++)
    {
        int copy_list = list + i * (pow(10, index - 1));
        my_print_combn_recursive(index - 1, i, max, copy_list);
    }
}

/// @brief Print all combinations of n different digits
/// @param n The number of digits to combine
/// @return ERROR if the input is invalid, NOERROR otherwise
int my_print_combn(int n)
{
    // Assert inputs
    if (assert_int_range(n, 1, 9))
        return ERROR;

    // Main code
    for (int i = 0; i < 11 - n; i++)
    {
        int list = i * pow(10, n - 1);
        my_print_combn_recursive(n - 1, i, n, list);
    }
    return NOERROR;
}