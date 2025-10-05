#include "include.h"

/* ----- Task 01 ----- */

/// @brief Compute the factorial of a non-negative integer iteratively
/// @param nb The non-negative integer
/// @return The factorial of nb, or 0 if nb is negative or if the result exceeds the range of int
int my_compute_factorial_it(int nb)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;

    // Main code
    if (nb < 0)
        return 0;
    int result = 1;
    for (int i = 1; i <= nb; i++)
        result *= i;
    return result;
}

/* ----- Task 02 ----- */

/// @brief Compute the factorial of a non-negative integer recursively
/// @param nb The non-negative integer
/// @return The factorial of nb, or 0 if nb is negative or if the result exceeds the range of int
int my_compute_factorial_rec(int nb)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;

    // Main code
    if (nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    return nb * my_compute_factorial_rec(nb - 1);
}

/* ----- Task 03 ----- */

/// @brief Compute the power of a number iteratively
/// @param nb The base
/// @param p The exponent
/// @return The result of nb raised to the power of p, or 0 if p is negative
int my_compute_power_it(int nb, int p)
{
    return pow(nb, p);
}

/* ----- Task 04 ----- */

/// @brief Compute the power of a number recursively
/// @param nb The base
/// @param p The exponent
/// @return The result of nb raised to the power of p, or 0 if p is negative
int my_compute_power_rec(int nb, int p)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;
    if (assert_int(p) == ERROR)
        return ERROR;

    // Main code
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return nb * my_compute_power_rec(nb, p - 1);
}

/* ----- Task 05 ----- */

/// @brief Compute the square root of a non-negative integer
/// @param nb The non-negative integer
/// @return The square root of nb, or 0 if nb is negative or if the result exceeds the range of int
int my_compute_square_root(int nb)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;

    // Main code
    if (nb <= 0)
        return 0;
    for (int i = nb; i > 0; i--)
    {
        if (i * i == nb)
            return i;
        if (i * i < nb)
            return 0;
    }
    return 0;
}

/* ----- Task 06 ----- */

/// @brief Check if a number is prime
/// @param nb The number to check
/// @return 1 if nb is prime, 0 otherwise
int my_is_prime(int nb)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;

    // Main code
    int count = 0;
    if (nb < 2)
        return FALSE;
    for (int i = 1; i <= nb; i++)
    {
        if (nb % i == 0)
            count++;
        if (count > 2)
            return FALSE;
    }
    return count == 2;
}

/* ----- Task 07 ----- */

/// @brief Find the smallest prime number greater than or equal to nb
/// @param nb The number to check
/// @return The smallest prime number greater than or equal to nb
int my_find_prime_sup(int nb)
{
    // Assert inputs
    if (assert_int(nb) == ERROR)
        return ERROR;

    // Main code
    if (my_is_prime(nb + 1))
        return nb + 1;
    return my_find_prime_sup(nb + 1);
}

/* ----- Task 08 ----- */

/// @brief Create an empty 2D array of integers
/// @param size The size of the array
/// @return A pointer to the 2D array
int **create_empty_array_2D_int(int size)
{
    // Assert inputs
    if (assert_int_range(size, 0, INT_MAX) == ERROR)
        return NULL;

    // Main code
    int **array = malloc(size * sizeof(int *));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        array[i] = malloc(size * sizeof(int));
        if (array[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(array[j]);
            free(array);
            return NULL;
        }
        for (int j = 0; j < size; j++)
            array[i][j] = 0;
    }
    return array;
}

/// @brief Create a copy of a 2D array of integers
/// @param base The base array to copy
/// @param size The size of the array
/// @return A pointer to the copied 2D array
int **create_copy_array_2D_int(int **base, int size)
{
    // Assert inputs
    if (base == NULL)
        return NULL;
    if (assert_int_range(size, 0, INT_MAX) == ERROR)
        return NULL;

    // Main code
    int **array = malloc(size * sizeof(int *));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        array[i] = malloc(size * sizeof(int));
        if (array[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(array[j]);
            free(array);
            return NULL;
        }
        for (int j = 0; j < size; j++)
            array[i][j] = base[i][j];
    }
    return array;
}

/// Private function for count_valid_queens_placements
int _add_queen(int a, int b, int **array, int size)
{
    array[a][b] = 2;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 2)
                continue;
            if (i == a || j == b)
                array[i][j] = 1;
            if (abs(a - i) == abs(b - j))
                array[i][j] = 1;
        }
    return 1;
}

/// @brief Free a 2D array of integers
/// @param array The 2D array to free
/// @param size The size of the array
void free_array_2D_int(int **array, int size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}

/// Private function for count_valid_queens_placements
int _can_place_n_queens(int a, int b, int size, int **base, int nb_queen)
{
    int **array = create_copy_array_2D_int(base, size);
    nb_queen += _add_queen(a, b, array, size);
    int count = 0;
    if (nb_queen == size)
    {
        free_array_2D_int(array, size);
        return 1;
    }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (array[i][j] == 0)
                count += _can_place_n_queens(i, j, size, array, nb_queen);
    free_array_2D_int(array, size);
    return count;
}

/// @brief Count the number of valid placements for n queens on an n x n chessboard
/// @param n The number of queens and the size of the chessboard
/// @return The number of valid placements, or -1 if n is negative or exceeds the range of int
int count_valid_queens_placements(int n)
{
    // Assert inputs
    if (assert_int(n))
        return ERROR;

    // Main code
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int **array = create_empty_array_2D_int(n);
            int nb_queen = 0;
            count += _can_place_n_queens(i, j, n, array, nb_queen);
            free_array_2D_int(array, n);
        }
    return count / my_compute_factorial_rec(n);
}
