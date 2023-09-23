#include "sort.h"

/**
 * print_list - Print a list of integers
 * @list: List to print
 */
void print_list(const listint_t *list)
{
	int i, i = 0;

	while (list)
	{
		if (i > 0)/* Print a comma separator if i is greater that 0*/
			printf(", ");

		/* Print the integer value of the node*/
		printf("%d", list->n);
		i++; /* Increment i by 1*/

		/* Update the list pointer to the next node*/
		list = list->next;
	}
	/* Print newline character*/
	printf("\n");
}
