#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 *              using the Heap sort algorithm (sift-down).
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    build_heap(array, size);

    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0);
    }
}

/**
 * build_heap - Builds a max heap from the array.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void build_heap(int *array, size_t size)
{
    for (size_t i = size / 2; i > 0; i--)
        sift_down(array, size, i - 1);
}

/**
 * sift_down - Moves the element at index down to its proper place.
 * @array: The array of integers.
 * @size: The size of the array.
 * @index: The index of the element to sift down.
 */
void sift_down(int *array, size_t size, size_t index)
{
    size_t max_index = index;
    size_t left_child = 2 * index + 1;
    size_t right_child = 2 * index + 2;

    if (left_child < size && array[left_child] > array[max_index])
        max_index = left_child;

    if (right_child < size && array[right_child] > array[max_index])
        max_index = right_child;

    if (max_index != index)
    {
        swap(&array[index], &array[max_index]);
        print_array(array, size);
        sift_down(array, size, max_index);
    }
}

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
