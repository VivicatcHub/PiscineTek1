#include "include.h"

/// @brief Displays an error message on the standard error output
/// @param str The error message to display
/// @return NOERROR on success, ERROR on failure
int my_puterror(char const *str)
{
    // Assert inputs
    if (str == NULL)
        return ERROR;

    // Main code
    for (int index = 0; str[index] != '\0'; index++)
        write(2, &str[index], 1);
    return NOERROR;
}

/// Private function for rush functions
void display_error()
{
    my_puterror("Invalid size\n");
}

/// Private function for rush functions
int is_coin(int i, int j, int x, int y)
{
    if (i == 0 && j == 0)
        return TRUE;
    if (i == (x - 1) && j == 0)
        return TRUE;
    if (i == 0 && j == (y - 1))
        return TRUE;
    if (i == (x - 1) && j == (y - 1))
        return TRUE;
    return FALSE;
}

/// Private function for rush functions
int is_side(int index, int max)
{
    if (index == 0)
        return TRUE;
    if (index == (max - 1))
        return TRUE;
    return FALSE;
}

/// Private function for rush functions
int is_horizontal(int j, int y)
{
    return is_side(j, y);
}

/// Private function for rush functions
int is_vertical(int i, int x)
{
    return is_side(i, x);
}

/// Private function for rush functions
void display_coin(int i, int j, int x, int y, struct characters chara)
{
    if (i == 0 && j == 0)
        my_putchar(chara.coin1);
    else if (i == (x - 1) && j == 0)
        my_putchar(chara.coin2);
    else if (i == 0 && j == (y - 1))
        my_putchar(chara.coin3);
    else if (i == (x - 1) && j == (y - 1))
        my_putchar(chara.coin4);
}

/// Private function for rush functions
int assert_struct_characters(struct characters *chara)
{
    if (chara == NULL)
        return ERROR;
    if (chara->coin1 == NULL || chara->coin2 == NULL || chara->coin3 == NULL || chara->coin4 == NULL)
        return ERROR;
    if (chara->horizontal == NULL || chara->vertical == NULL)
        return ERROR;
    return NOERROR;
}

/// Private function for rush functions
void rush_special(int x, int y, struct characters chara)
{
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
            my_putchar(chara.special);
        my_putchar('\n');
    }
}

/// Private function for rush functions
void rush_normal(int x, int y, struct characters chara)
{
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            if (is_coin(i, j, x, y))
                display_coin(i, j, x, y, chara);
            else if (is_horizontal(j, y))
                my_putchar(chara.horizontal);
            else if (is_vertical(i, x))
                my_putchar(chara.vertical);
            else
                my_putchar(' ');
        }
        my_putchar('\n');
    }
}

/// @brief Generic rush function
/// @param x The width of the rush
/// @param y The height of the rush
/// @param chara The characters to use for the rush
void rush_generic(int x, int y, struct characters chara)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();
    if (assert_struct_characters(&chara) == ERROR)
        return display_error();

    // Main code
    if (chara.special != NULL && (x == 1 || y == 1))
        rush_special(x, y, chara);
    else
        rush_normal(x, y, chara);
}

/// @brief Rush pattern 1
/// @param x The width of the rush
/// @param y The height of the rush
void rush11(int x, int y)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();

    // Main code
    struct characters chara = {'o', 'o', 'o', 'o', '-', '|'};
    rush_generic(x, y, chara);
    return;
}

/// @brief Rush pattern 2
/// @param x The width of the rush
/// @param y The height of the rush
void rush12(int x, int y)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();

    // Main code
    struct characters chara = {'/', '\\', '\\', '/', '*', '*', '*'};
    rush_generic(x, y, chara);
    return;
}

/// @brief Rush pattern 3
/// @brief Rush pattern 2
/// @param x The width of the rush
/// @param y The height of the rush
/// @param x The width of the rush
/// @param y The height of the rush
void rush13(int x, int y)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();

    // Main code
    struct characters chara = {'A', 'A', 'C', 'C', 'B', 'B', 'B'};
    rush_generic(x, y, chara);
    return;
}

/// @brief Rush pattern 4
/// @param x The width of the rush
/// @param y The height of the rush
void rush14(int x, int y)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();

    // Main code
    struct characters chara = {'A', 'C', 'A', 'C', 'B', 'B', 'B'};
    rush_generic(x, y, chara);
    return;
}

/// @brief Rush pattern 5
/// @param x The width of the rush
/// @param y The height of the rush
void rush15(int x, int y)
{
    // Assert inputs
    if (assert_int_range(x, 1, INT_MAX) == ERROR || assert_int_range(y, 1, INT_MAX) == ERROR)
        return display_error();

    // Main code
    struct characters chara = {'A', 'C', 'C', 'A', 'B', 'B', 'B'};
    rush_generic(x, y, chara);
    return;
}