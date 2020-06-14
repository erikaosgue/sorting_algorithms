#include "sort.h"

/**
 * insertion_sort_list - sort a double linked list of int
 * @list: Pointer to the head of the double linked list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *checker = NULL, *sig = NULL;

	if (list == NULL || *list == NULL)
		return;

	sig  = current = *list;
	while (sig)
	{
		checker = current;
		sig = sig->next;
		while (checker)
		{
			if (current->n < checker->n)
			{
				current->prev->next = current->next;
				if (current->next)
					current->next->prev = current->prev;

				current->prev = checker->prev;
				current->next = checker;
				if (checker->prev)
					checker->prev->next = current;
				else
					*list = current;
				checker->prev = current;
				print_list(*list);
			}
			else if (current != checker)
				break;
			checker = checker->prev;
		}
		current = sig;
	}
}
