#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void merge_sort_recursive(int *array, size_t size)
{
    size_t mid, i;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;

    left = array;
    right = array + mid;

    printf("Merging...\n[left]: ");
    print_array(left, mid);
    printf("[right]: ");
    print_array(right, size - mid);

    merge_sort_recursive(left, mid);
    merge_sort_recursive(right, size - mid);

    merge_arrays(array, left, mid, right, size - mid);

    printf("[Done]: ");
    print_array(array, size);

    /* Free dynamically allocated memory (only one call) */
    free(left);
}

/**
 * merge_arrays - Merges two arrays into a sorted array.
 * @array: The array to merge into.
 * @left: The left sub-array.
 * @left_size: The size of the left sub-array.
 * @right: The right sub-array.
 * @right_size: The size of the right sub-array.
 */
void merge_arrays(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *merged;

    merged = malloc((left_size + right_size) * sizeof(int));
    if (merged == NULL)
        return;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            merged[k++] = left[i++];
        }
        else
        {
            merged[k++] = right[j++];
        }
    }

    while (i < left_size)
    {
        merged[k++] = left[i++];
    }

    while (j < right_size)
    {
        merged[k++] = right[j++];
    }

    for (i = 0; i < left_size + right_size; i++)
    {
        array[i] = merged[i];
    }

    free(merged);
}
