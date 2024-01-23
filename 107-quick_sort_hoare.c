#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm with Hoare partition scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_hoare_recursive - Recursively sorts a partition of the array.
 * @array: The array of integers to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */

void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        quicksort_hoare_recursive(array, low, pivot, size);
        quicksort_hoare_recursive(array, pivot + 1, high, size);
    }
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme.
 * @array: The array of integers to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot.
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap_elements(array, i, j);
            print_array(array, size);
        }
        else
        {
            return j;
        }
    }
}

/**
 * swap_elements - Swaps two elements in an array.
 * @array: The array of integers.
 * @i: Index of the first element to be swapped.
 * @j: Index of the second element to be swapped.
 */

void swap_elements(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
