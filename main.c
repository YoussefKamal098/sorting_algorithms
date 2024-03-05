#include "deck.h"
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * print_deck -  Prints the contents of a deck of cards to the standard output.
 *
 * This function takes a pointer to the head of a doubly linked list
 * representing a deck of cards (`deck`) and prints the cards in the
 * deck to the standard output stream (usually the console).
 *
 * @deck: A pointer to the head of the deck of cards to print.
 *
 * Return: void (no return value).
 *
 * Note: This function assumes the `deck.h` header file is included,
 * which defines the `deck_node_t` structure used for the linked list
 * nodes and the `card_t` structure representing each card.
 */
void print_deck(const deck_node_t *deck)
{
	size_t i;
	char kinds[4] = {'S', 'H', 'C', 'D'};

	i = 0;
	while (deck)
	{
		if (i)
			printf(", ");
		printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
		if (i == 12)
			printf("\n");
		i = (i + 1) % 13;
		deck = deck->next;
	}
}

/**
 * init_deck - Initializes a deck of cards from a given array of cards.
 *
 * This function takes an array of `card_t` structures (`cards`)
 * representing 52 cards and returns a pointer to the head of a newly
 * created doubly linked list representing the deck of cards.
 *
 * @cards: An array of 52 `card_t` structures representing the cards in the deck.
 *
 * Return: A pointer to the head of the newly created deck of cards,
 * or NULL on failure (e.g., memory allocation error).
 *
 * Note: This function assumes the `deck.h` header file is included,
 * which defines the `deck_node_t` structure used for the linked
 * list nodes and the `card_t` structure representing each card.
 */
deck_node_t *init_deck(const card_t cards[52])
{
	deck_node_t *deck;
	deck_node_t *node;
	size_t i;

	i = 52;
	deck = NULL;
	while (i--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		node->card = &cards[i];
		node->next = deck;
		node->prev = NULL;
		if (deck)
			deck->prev = node;
		deck = node;
	}
	return (deck);
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	card_t cards[52] = {
	    {"Jack", CLUB},
	    {"4", HEART},
	    {"3", HEART},
	    {"3", DIAMOND},
	    {"Queen", HEART},
	    {"5", HEART},
	    {"5", SPADE},
	    {"10", HEART},
	    {"6", HEART},
	    {"5", DIAMOND},
	    {"6", SPADE},
	    {"9", HEART},
	    {"7", DIAMOND},
	    {"Jack", SPADE},
	    {"Ace", DIAMOND},
	    {"9", CLUB},
	    {"Jack", DIAMOND},
	    {"7", SPADE},
	    {"King", DIAMOND},
	    {"10", CLUB},
	    {"King", SPADE},
	    {"8", CLUB},
	    {"9", SPADE},
	    {"6", CLUB},
	    {"Ace", CLUB},
	    {"3", SPADE},
	    {"8", SPADE},
	    {"9", DIAMOND},
	    {"2", HEART},
	    {"4", DIAMOND},
	    {"6", DIAMOND},
	    {"3", CLUB},
	    {"Queen", CLUB},
	    {"10", SPADE},
	    {"8", DIAMOND},
	    {"8", HEART},
	    {"Ace", SPADE},
	    {"Jack", HEART},
	    {"2", CLUB},
	    {"4", SPADE},
	    {"2", SPADE},
	    {"2", DIAMOND},
	    {"King", CLUB},
	    {"Queen", SPADE},
	    {"Queen", DIAMOND},
	    {"7", CLUB},
	    {"7", HEART},
	    {"5", CLUB},
	    {"10", DIAMOND},
	    {"4", CLUB},
	    {"King", HEART},
	    {"Ace", HEART},
	};
	deck_node_t *deck;

	deck = init_deck(cards);
	print_deck(deck);
	printf("\n");
	sort_deck(&deck);
	printf("\n");
	print_deck(deck);
	return (0);
}