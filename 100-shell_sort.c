#include "sort.h"
/**
 * swap_ints - Swaps integers in an array.
 * @x: 1st integer to be swapped.
 * @y: 2nd integer to be swapped.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ;

    for (; gap > 0; gap /= 3)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        print_array(array, size);
    }
}
