#include "sort.h"

/**
 * swaps - swaps current and forward Nodes
 * @current: Pointer to the left next to forward
 * @forward: Pointer to the right next to current;
 * @list: Pointer to the head of the list
 */

void swaps(listint_t *current, listint_t *forward, listint_t **list)
{
	if (current->prev)
		current->prev->next = forward;
	if (forward->next)
		forward->next->prev = current;
	forward->prev = current->prev;
	current->next = forward->next;
	current->prev = forward;
	forward->next = current;
	if (forward->prev == NULL)
		*list = forward;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *end_pointer = NULL;
	listint_t *forward = NULL;
	int to_right = 1, finish_swap = 1;

	if (list == NULL || *list == NULL)
		return;

	current = forward = *list;
	while (1)
	{	/* the pointers current and forward go to the right */
		if (to_right == 1)
		{
			current = forward;
			forward = forward->next;
			end_pointer = forward;
		}
		/* the pointers curr and fowards go to the left */
		else
		{
			forward = current;
			current = current->prev;
			end_pointer = current;
		}
		/* check if the curr or forw pointer reach the NULL */
		if (end_pointer == NULL)
		{
			to_right *= -1;
			if (finish_swap != 0)
				break;
			finish_swap = 1;
		}
		/* check the if current > forward swaps */
		if (forward && current && current->n > forward->n)
		{
			swaps(current, forward, list);
			current = forward;
			forward = forward->next;
			finish_swap = 0;
		}
	}
}
