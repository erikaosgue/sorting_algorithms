#include "deck.h"

/**
 * swaps - swaps current and forward Nodes
 * @current: Pointer to the left next to forward
 * @forward: Pointer to the right next to current;
 * @deck: Pointer to the head of the deck
 */
void swaps(deck_node_t *current, deck_node_t *forward, deck_node_t **deck)
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
		*deck = forward;
}

/**
 * cocktail_sort_deck - sorts a doubly linked deck of integers
 * using the Cocktail shaker sort algorithm
 *
 * @deck: Pointer to the head of the deck
 * @mode: switch to ask for kind or value of the card
 */
void cocktail_sort_deck(deck_node_t **deck, int mode)
{
	deck_node_t *current = NULL, *end_pointer = NULL;
	deck_node_t *forward = NULL;
	int to_right = 1, finish_swap = 1;

	current = forward = *deck;
	while (1)
	{ /* the pointers current and forward go to the right */
		if (to_right == 1)
		{ current = forward;
			forward = forward->next;
			end_pointer = forward;
		}
		/* the pointers curr and fowards go to the left */
		else
		{ forward = current;
			current = current->prev;
			end_pointer = current;
		}
		/* check if the curr or forw pointer reach the NULL */
		if (end_pointer == NULL)
		{ to_right *= -1;
			if (finish_swap != 0)
				break;
			finish_swap = 1;
		}
		if (mode == 0)
		{
			if (forward && current && current->card->kind > forward->card->kind)
			{ swaps(current, forward, deck), current = forward;
				forward = forward->next, finish_swap = 0;
			}
		}
		else if (mode == 1)
		{
			if (forward && current && current->card->value[0] > forward->card->value[0])
			{ swaps(current, forward, deck), current = forward;
				forward = forward->next, finish_swap = 0;
			}
		}
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: double pointer to the double linked list of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *head_S = NULL, *head_H = NULL, *head_C = NULL, *head_D = NULL;
	deck_node_t *tail_S = NULL, *tail_H = NULL, *tail_C = NULL, *tail_D = NULL;

	if (deck == NULL || *deck == NULL)
		return;

	cocktail_sort_deck(deck, 0);

	divide(deck, &head_S, &head_H, &head_C,
	&head_D, &tail_S, &tail_H, &tail_C, &tail_D);

	/* S */
	cocktail_sort_deck(&head_S, 1);
	strange_swap_and_update_tail(&head_S, &tail_S);
	*deck = head_S;
	/* H */
	cocktail_sort_deck(&head_H, 1);
	strange_swap_and_update_tail(&head_H, &tail_H);
	/* C */
	cocktail_sort_deck(&head_C, 1);
	strange_swap_and_update_tail(&head_C, &tail_C);
	/* D */
	cocktail_sort_deck(&head_D, 1);
	strange_swap_and_update_tail(&head_D, &tail_D);

	tail_S->next = head_H;
	head_H->prev = tail_S;

	tail_H->next = head_C;
	head_C->prev = tail_H;

	tail_C->next = head_D;
	head_D->prev = tail_C;
}

/**
 * strange_swap_and_update_tail - to fix card A and 10
 * @head: head
 * @tail: tail
 */
void strange_swap_and_update_tail(deck_node_t **head, deck_node_t **tail)
{
	deck_node_t *a, *b, *second;
	int i;

	a = b = *head;
	second = (*head)->next;
	*tail = *head;
	for (i = 0; i < 12; i++)
	{
		*tail = (*tail)->next;
		if (i < 9)
			b = b->next;
	}

	/* para bajar la a */
	b->prev->next = a;
	b->next->prev = a;
	a->next = b->next;
	a->prev = b->prev;

	/* para subir la b */
	b->next = second;
	b->prev = NULL;
	*head = b;

	swaps((*tail)->prev, *tail, head);
	*tail = (*tail)->next;
}

void divide(deck_node_t **deck,
deck_node_t **head_S, deck_node_t **head_H,
deck_node_t **head_C, deck_node_t **head_D,
deck_node_t **tail_S, deck_node_t **tail_H,
deck_node_t **tail_C, deck_node_t **tail_D)
{
	int i;
	deck_node_t *current = NULL;

	*head_S = *deck;
	current = *deck;
	for (i = 0; i < 12; i++)
		current = current->next;
	*tail_S = current;
	*head_H = current->next;
	(*tail_S)->next = NULL;
	(*head_H)->prev = NULL;

	current = *head_H;
	for (i = 0; i < 12; i++)
		current = current->next;
	*tail_H = current;
	*head_C = current->next;
	(*tail_H)->next = NULL;
	(*head_C)->prev = NULL;

	current = *head_C;
	for (i = 0; i < 12; i++)
		current = current->next;
	*tail_C = current;
	*head_D = current->next;
	(*tail_C)->next = NULL;
	(*head_D)->prev = NULL;

	current = *head_D;
	for (i = 0; i < 12; i++)
		current = current->next;
	*tail_D = current;
}
