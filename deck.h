#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumerates the four suits of a playing card.
 *
 * This enumeration defines the different suits (or kinds) that
 * a playing card can belong to. Each member of the enum has a
 * corresponding integer value, starting from 0.
 *
 * @SPADE: The spade suit.
 * @HEART: The heart suit.
 * @CLUB: The club suit.
 * @DIAMOND: The diamond suit.
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

/* 1000-sort_deck */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
