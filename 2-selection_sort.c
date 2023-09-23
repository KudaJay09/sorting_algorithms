#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order
 * @size: size of the array
 * @array: the array to be sorted
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t count, idx;
	int swp, temp;
	int flag = 0;

	if (array == NULL)
		return;
	for (count = 0; count < size; count++)
	{
		temp = count;
		flag = 0;
		for (idx = count + 1; idx < size; idx++)
		{
			if (array[temp] > array[idx])
			{
				temp = idx;
				flag += 1;
			}
		}
		swp = array[count];
		array[count] = array[temp];
		array[temp] = swp;
		if (flag != 0)
			print_array(array, size);
	}
}
