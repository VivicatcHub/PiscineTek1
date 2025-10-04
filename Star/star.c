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
int get_bar_size(int size)
{
    return size * 2 + 1;
}

/// Private function for star
int get_middle_size(int size)
{
    return max(get_bar_size(size - 2), 1);
}

/// Private function for star
void display_spine(unsigned int size, int index)
{
    int nb = get_bar_size(size) + (size - index - 1) - (size != 1);
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
void display_head(unsigned int size)
{
    for (int i = 0; i < (int)size; i++)
        display_spine(size, i);
}

/// Private function for star
void display_down(unsigned int size)
{
    for (int i = size - 1; i >= 0; i--)
        display_spine(size, i);
}

/// Private function for star
void display_bar(unsigned int size)
{
    int nb = get_bar_size(size);
    for (int i = 0; i < nb; i++)
        my_putchar('*');
    for (int i = 0; i < get_middle_size(size); i++)
        my_putchar(' ');
    for (int i = 0; i < nb; i++)
        my_putchar('*');
    my_putchar('\n');
}

/// Private function for star
int display_side_line(unsigned int size, int count)
{
    for (int j = 0; j < count; j++)
        my_putchar(' ');
    my_putchar('*');
    for (int j = 0; j < get_bar_size(size) * 2 - (count * 2) - 2 + get_middle_size(size); j++)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
    return 1;
}

/// Private function for star
void display_side(unsigned int size)
{
    int count = 1;
    for (int i = 1; i < (int)size; i++)
        count += display_side_line(size, count);
    for (int i = 0; i < (int)size; i++)
        count -= display_side_line(size, count);
}

/// @brief Create a star pattern
/// @param size The size of the star
/// @return void
void star(unsigned int size)
{
    display_head(size);
    display_bar(size);
    display_side(size);
    display_bar(size);
    display_down(size);
}
