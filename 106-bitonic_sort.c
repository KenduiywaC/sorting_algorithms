#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || !is_power_of_two(size))
        return;

    printf("Merging [0/%lu] (UP):\n", size);
    print_array(array, size);
    bitonic_merge(array, size, 1, ASCENDING);
}

/**
 * bitonic_merge - Recursively merges two halves of the array.
 * @array: The array of integers to be merged.
 * @size: The size of the array.
 * @step: The current step in the Bitonic sort algorithm.
 * @order: The order of merging (ASCENDING or DESCENDING).
 */
void bitonic_merge(int *array, size_t size, size_t step, int order)
{
    if (size < 2)
        return;

    size_t half_size = size / 2;

    printf("Merging [%lu/%lu] (%s):\n", half_size, size, order == ASCENDING ? "UP" : "DOWN");
    print_array(array, size);

    bitonic_compare(array, size, step, order);
    bitonic_merge(array, half_size, step * 2, ASCENDING);
    bitonic_merge(array + half_size, half_size, step * 2, DESCENDING);
}

/**
 * bitonic_compare - Compares and swaps elements based on Bitonic order.
 * @array: The array of integers to be compared and swapped.
 * @size: The size of the array.
 * @step: The current step in the Bitonic sort algorithm.
 * @order: The order of comparing (ASCENDING or DESCENDING).
 */
void bitonic_compare(int *array, size_t size, size_t step, int order)
{
    size_t i, j, k;

    for (i = 0; i < size; i++)
    {
        j = i ^ step;
        if ((j > i) == order && array[i] > array[j])
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            printf("Result [%lu/%lu] (%s):\n", i + 1, size, order == ASCENDING ? "UP" : "DOWN");
            print_array(array, size);
        }
    }
}

/**
 * is_power_of_two - Checks if a number is a power of two.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is a power of two, 0 otherwise.
 */
int is_power_of_two(size_t n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

/**
 * print_array - Prints the elements of an array.
 * @array: The array of integers to be printed.
 * @size: The size of the array.
 */
void print_array(int *array, size_t size)
{
    size_t i;

    printf("%d", array[0]);
    for (i = 1; i < size; i++)
        printf(", %d", array[i]);
    printf("\n");
}
