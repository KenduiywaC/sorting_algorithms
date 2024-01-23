#include "sort.h"

/**
 * swap_ints - Swaps integers in an array.
 * @x: First integer to be swapped.
 * @y: Second integer to be swapped.
 */
void swap_ints(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (i != min_index)
        {
            swap_ints(&array[i], &array[min_index]);
            print_array(array, size);
        }
    }
}

