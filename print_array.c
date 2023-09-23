#include "sort.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the array to print
 * @size: size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	/* Ilerate over each element in the array*/
	for (i = 0; i < size; i++)
    {
	    /* Print the element*/
        printf("%d", array[i]);
        if (i != size - 1)

	/* Print comma and a space after the element*/
            printf(", ");
    }
	/* Newline character to move to the next line*/
    printf("\n");
}
