#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - Type of the cards
 * @SPADE: 0
 * @HEART: 1
 * @CLUB: 2
 * @DIAMOND: 3
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
void swaps(deck_node_t *current, deck_node_t *forward, deck_node_t **deck);
void cocktail_sort_list(deck_node_t **deck);
void print_deck(const deck_node_t *deck);
deck_node_t *init_deck(const card_t cards[]);
void divide(deck_node_t **deck,
deck_node_t **head_S, deck_node_t **head_H,
deck_node_t **head_C, deck_node_t **head_D,
deck_node_t **tail_S, deck_node_t **tail_H,
deck_node_t **tail_C, deck_node_t **tail_D);
#endif /* DECK_H */
