#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (current = start = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(&start, &current);
				print_list((const listint_t *)start);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (current = end = current->prev; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(&start, &current);
				print_list((const listint_t *)start);
				swapped = 1;
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @start: A pointer to the start node.
 * @current: A pointer to the current node.
 */
void swap_nodes(listint_t **start, listint_t **current)
{
	listint_t *prev_node = (*current)->prev;
	listint_t *next_node = (*current)->next;

	if (prev_node != NULL)
		prev_node->next = next_node;
	else
		*start = next_node;
	next_node->prev = prev_node;
	(*current)->prev = next_node;
	(*current)->next = next_node->next;
	next_node->next = *current;
	if ((*current)->next != NULL)
		(*current)->next->prev = *current;
}
