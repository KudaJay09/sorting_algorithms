#include "sort.h"

/**
 * quick_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs_part(array, 0, size - 1, size);
}
/**
 * qs_part - sorts partition according to pivot
 * @array: original array
 * @first: first element of array
 * @last: last element of array
 * @size: size of original array
 */
void qs_part(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qs(array, first, position - 1, size);
		qs(array, position + 1, last, size);
	}
}

/**
 * swap - swap value of array elements
 * @array: array (for print)
 * @size: size of array (for print)
 * @obj: object in array element
 */
void swap(int *array, ssize_t size, ssize_t obj)
{
	int tmp;

	tmp = array[size];
	array[size] = array[obj];
	array[obj] = tmp;
}

/**
 *lomuto_part - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_part(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}
