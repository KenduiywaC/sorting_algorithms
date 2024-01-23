#include "sort.h"

/**
 * swap_ints - Swaps integers in an array.
 * @x: 1st integer to be swapped.
 * @y: 2nd integer to be swapped.
 */
void swap_ints(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * lomuto_partition - Partition a subset of an array using the Lomuto scheme.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @left: Starting index of the subset.
 * @right: Ending index of the subset.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot = array + right;
    int above, below;

    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Implement quicksort through recursion (Lomuto scheme).
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 * @left: Starting index of the array partition.
 * @right: Ending index of the array partition.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order (quicksort).
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
