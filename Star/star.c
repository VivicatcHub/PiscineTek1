#include "include.h"

/// @brief Get the maximum of two integers
/// @param a The first integer
/// @param b The second integer
/// @return The maximum of a and b
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

/// Private function for star
int _get_bar_size(int size)
{
    return size * 2 + 1;
}

/// Private function for star
int _get_middle_size(int size)
{
    return max(_get_bar_size(size - 2), 1);
}

/// Private function for star
void _display_spine(unsigned int size, int index)
{
    int nb = _get_bar_size(size) + (size - index - 1) - (size != 1);
    for (int j = 0; j < nb; j++)
        my_putchar(' ');
    my_putchar('*');
    if (index != 0)
    {
        for (int j = 0; j < ((index - 1) * 2) + 1; j++)
            my_putchar(' ');
        my_putchar('*');
    }
    my_putchar('\n');
}

/// Private function for star
void _display_head(unsigned int size)
{
    for (int i = 0; i < (int)size; i++)
        _display_spine(size, i);
}

/// Private function for star
void _display_down(unsigned int size)
{
    for (int i = size - 1; i >= 0; i--)
        _display_spine(size, i);
}

/// Private function for star
void _display_bar(unsigned int size)
{
    int nb = _get_bar_size(size);
    for (int i = 0; i < nb; i++)
        my_putchar('*');
    for (int i = 0; i < _get_middle_size(size); i++)
        my_putchar(' ');
    for (int i = 0; i < nb; i++)
        my_putchar('*');
    my_putchar('\n');
}

/// Private function for star
int _display_side_line(unsigned int size, int count)
{
    for (int j = 0; j < count; j++)
        my_putchar(' ');
    my_putchar('*');
    for (int j = 0; j < _get_bar_size(size) * 2 - (count * 2) - 2 + _get_middle_size(size); j++)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
    return 1;
}

/// Private function for star
void _display_side(unsigned int size)
{
    int count = 1;
    for (int i = 1; i < (int)size; i++)
        count += _display_side_line(size, count);
    for (int i = 0; i < (int)size; i++)
        count -= _display_side_line(size, count);
}

/// @brief  Check if an integer is within the range of a standard 32-bit unsigned integer
/// @param integer The integer to check
/// @return ERROR if the integer is out of range, NOERROR otherwise
int assert_uint(long long integer)
{
    if (assert_int_range(integer, 0, UINT_MAX) == ERROR)
        return ERROR;
    return NOERROR;
}

/// @brief Create a star pattern
/// @param size The size of the star
/// @return void
void star(unsigned int size)
{
    // Assert inputs
    if (assert_uint(size) == ERROR)
        return;

    // Main code
    _display_head(size);
    _display_bar(size);
    _display_side(size);
    _display_bar(size);
    _display_down(size);
}
