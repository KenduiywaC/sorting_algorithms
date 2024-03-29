#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output;
    int max, i;

    if (array == NULL || size < 2)
        return;

    max = find_max(array, size);

    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

   
    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < (int)size; i++)
        count[array[i]]++;
    print_array(count, max + 1);

    
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];
    
    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    free(count);
    free(output);
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
