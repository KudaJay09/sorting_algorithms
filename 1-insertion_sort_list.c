#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @list: pointer to the head of the doubly linked list
 * @list1: pointer to the first node to swap
 * @list2: pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t **list1, listint_t *list2)
{
	(*list1)->next = list2->next;
	if (list2->next != NULL)
		list2->next->prev = *list1;
	list2->prev = (*list1)->prev;
	list2->next = *list1;

	if ((*list1)->prev != NULL)
		(*list1)->prev->next = list2;

	else
		*list = list2;
	(*list1)->prev = list2;
	*list1 = list2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    /* Check if the list is valid and has more than one element */
    if (!list || !(*list) || !((*list)->next))
        return;

    /* Iterate from the second element to the end of the list */
    current = (*list)->next;
    while (current)
    {
        /* Store the next element and initialize the insert position */
        insert = current->next;

        /* Iterate from the current element to the beginning of the list */
        while (current->prev && current->n < current->prev->n)
        {
            /* Swap the current element with the previous one */
            swap_nodes(list, current->prev, current);
            /* Continue until the current element is in the right position */
        }
        /* Move to the next element */
        current = insert;
    }
}
