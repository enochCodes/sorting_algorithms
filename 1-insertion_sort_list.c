#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			temp = sorted->prev;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			current->prev = sorted->prev;
			sorted->prev = current;
			sorted->next = current->next;
			current->next = sorted;
			if (sorted->next != NULL)
				sorted->next->prev = sorted;
			sorted = temp;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
