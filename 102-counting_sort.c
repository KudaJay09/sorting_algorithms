#include "sort.h"
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    int i, j, max = 0;
    int *count = NULL, *output = NULL;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < (int)size; i++)
        max = array[i] > max ? array[i] : max;

    /* Allocate memory for the count and output arrays */
    count = malloc(sizeof(int) * (max + 1));
    if (!count)
        return;

    output = malloc(sizeof(int) * size);
    if (!output)
    {
        free(count);
        return;
    }

    /* Initialize all elements of the count array to zero */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the occurrences of each element in the array */
    for (j = 0; j < (int)size; j++)
        count[array[j]]++;

    /* Modify the count array to contain the number of elements less than or equal to each element */
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Print the resulting count array */
    print_array(count, max + 1);

    /* Place each element in its correct position in the output array */
    for (j = size - 1; j >= 0; j--)
    {
        output[count[array[j]] - 1] = array[j];
        count[array[j]]--;
    }

    /* Copy the sorted elements from the output array back into the original array */
    for (j = 0; j < (int)size; j++)
        array[j] = output[j];

    /* Free dynamically allocated memory */
    free(output);
    free(count);
}
