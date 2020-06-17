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
	/* print_deck(*deck); */
}

/**
 * cocktail_sort_deck - sorts a doubly linked deck of integers
 * using the Cocktail shaker sort algorithm
 *
 * @deck: Pointer to the head of the deck
 */
void cocktail_sort_deck(deck_node_t **deck)
{
	deck_node_t *current = NULL, *end_pointer = NULL;
	deck_node_t *forward = NULL;
	int to_right = 1, finish_swap = 1;

	if (deck == NULL || *deck == NULL)
		return;

	current = forward = *deck;
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
		if (forward && current && current->card->kind > forward->card->kind)
		{
			swaps(current, forward, deck);
			current = forward;
			forward = forward->next;
			finish_swap = 0;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards
 * 
 * 
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *head_S = NULL, *head_H = NULL, *head_C = NULL, *head_D = NULL;
	deck_node_t *tail_S = NULL, *tail_H = NULL, *tail_C = NULL, *tail_D = NULL;

	(void)*head_S;
	(void)*head_H;
	(void)*head_C;
	(void)*head_D;
	(void)*tail_S;
	(void)*tail_H;
	(void)*tail_C;
	(void)*tail_D;
	cocktail_sort_deck(deck);
	
	divide(deck, &head_S, &head_H, &head_C,
	&head_D, &tail_S, &tail_H, &tail_C, &tail_D);

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