#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max_value = find_max(array, size);
    int exp;

    for (exp = 1; max_value / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort - Sorts an array of integers based on a digit place.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @exp: The digit place to consider.
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output, *count;
    size_t i;
    const int base = 10;

    output = malloc(size * sizeof(int));
    count = malloc(base * sizeof(int));

    if (output == NULL || count == NULL)
    {
        free(output);
        free(count);
        return;
    }

    for (i = 0; i < base; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % base]++;

    for (i = 1; i < base; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % base] - 1] = array[i];
        count[(array[i] / exp) % base]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

/**
 * find_max - Finds the maximum element in an array.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum element in the array.
 */

int find_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}
