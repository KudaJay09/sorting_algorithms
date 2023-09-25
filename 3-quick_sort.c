#include "sort.h"
void qs_part(int *array, size_t size, size_t left, size_t right);
void swap(int *array, size_t size, int *a, int *b);
/**
 * quick_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		qs_part(array, size, 0, size - 1);
}
/**
 * qs_part - sorts partition according to pivot
 * @array: original array
 * @size: size of original array
 * @left: leftmost element of partition
 * @right: rightmost element of partition
 */
void qs_part(int *array, size_t size, size_t left, size_t right)
{
	int pivot = array[right];
	size_t i, j;

	if (left < right)
	{
		for (i = j = left; j < right; j++)
		{
			if (array[j] <= pivot)
			{
				swap(array, size, &array[j], &array[i]);
				i++;
			}
		}
		swap(array, size, &array[j], &array[i]);

		if (i > 0)
			qs_part(array, size, left, i - 1);

		qs_part(array, size, i + 1, right);
	}
}
/**
 * swap - swap value of array elements
 * @array: array (for print)
 * @size: size of array (for print)
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(arr, size);
	}
}
