#include "include.h"

int main(void)
{
    // my_swap
    printf("my_swap:\n");
    int x = 5;
    int y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    my_swap(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);

    // my_putstr
    printf("\nmy_putstr:\n");
    const char *test_str = "Hello, World!\n";
    my_putstr(test_str);
    my_putstr("");
    my_putstr(NULL);

    // my_strlen
    printf("\nmy_strlen:\n");
    const char *len_str = "Hello, World!";
    int length = my_strlen(len_str);
    printf("Length of '%s' is %d\n", len_str, length);
    const char *len_str2 = "";
    int length2 = my_strlen(len_str2);
    printf("Length of '%s' is %d\n", len_str2, length2);
    const char *len_str3 = NULL;
    int length3 = my_strlen(len_str3);
    printf("Length of '%s' is %d\n", len_str3, length3);

    // my_evil_str
    printf("\nmy_evil_str:\n");
    char evil_str[] = "Hello, World!";
    printf("Original string: %s\n", evil_str);
    my_evil_str(evil_str);
    printf("Reversed string: %s\n", evil_str);
    char evil_str2[] = "?";
    printf("Original string: %s\n", evil_str2);
    my_evil_str(evil_str2);
    printf("Reversed string: %s\n", evil_str2);

    // my_getnbr
    printf("\nmy_getnbr:\n");
    const char *num_str = "+---+--++---+---+---+-42";
    int number = my_getnbr(num_str);
    printf("String '%s' converted to number: %d\n", num_str, number);
    const char *num_str2 = "42a43";
    int number2 = my_getnbr(num_str2);
    printf("String '%s' converted to number: %d\n", num_str2, number2);
    const char *num_str3 = "11000000000000000000000042";
    int number3 = my_getnbr(num_str3);
    printf("String '%s' converted to number: %d\n", num_str3, number3);
    const char *num_str4 = "-1000000000000000000000042";
    int number4 = my_getnbr(num_str4);
    printf("String '%s' converted to number: %d\n", num_str4, number4);
    const char *num_str5 = NULL;
    int number5 = my_getnbr(num_str5);
    printf("String '%s' converted to number: %d\n", num_str5, number5);

    // my_sort_int_array
    printf("\nmy_sort_int_array:\n");
    int arr[] = {5, 3, 8, 1, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    my_sort_int_array(arr, size);
    printf("Sorted array:   ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // my_quick_sort_int_array
    printf("\nmy_quick_sort_int_array:\n");
    int array[] = {5, 3, 8, 1, 2, 7};
    int size_arr = sizeof(array) / sizeof(array[0]);
    printf("Original array: ");
    for (int i = 0; i < size_arr; i++)
        printf("%d ", array[i]);
    printf("\n");
    my_quick_sort_int_array(array, size_arr);
    printf("Sorted array:   ");
    for (int i = 0; i < size_arr; i++)
        printf("%d ", array[i]);
    printf("\n");
}