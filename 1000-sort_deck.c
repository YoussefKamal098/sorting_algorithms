#include <stdio.h>
#include "deck.h"

int compare_cards_kind(const void *a, const void *b);
int compare_cards_value(const void *a, const void *b);
int _strcmp(const char *str1, const char *str2);
long int _atoi(const char *str);

/**
 * sort_deck - Sorts a deck of cards in ascending order by suit and value.
 *
 * This function takes a pointer to the head of a doubly linked list
 * representing a deck of cards as input. It sorts the cards in the deck
 * first by suit (Spades < Hearts < Clubs < Diamonds) and then by value
 * (Ace < 2 < ... < King) within each suit.
 *
 * @deck: A pointer to the head of a doubly linked list representing
 * the deck of cards to sort.
 *
 * Return: void (no return value).
 *
 * Note: The function assumes the `deck.h` header file is included,
 * which defines the `deck_node_t` structure used for the linked list
 * nodes and the `card_t` structure representing each card.
 */
void sort_deck(deck_node_t **deck)
{
	size_t list_size = 0, i;
	deck_node_t *curr, **card_array, **card_sub_array;

	if (!deck || !*deck)
		return;

	curr = *deck;
	while (curr)
	{
		list_size++;
		curr = curr->next;
	}

	card_array = malloc(sizeof(*card_array) * (list_size + 1));
	if (!card_array)
		return;

	curr = *deck;
	i = 0;
	while (curr)
	{
		card_array[i++] = curr;
		curr = curr->next;
	}
	card_array[i] = NULL;

	qsort(card_array, list_size, sizeof(*card_array), compare_cards_kind);

	for (card_sub_array = card_array; *card_sub_array; card_sub_array += 13)
		qsort(card_sub_array, 13, sizeof(*card_sub_array), compare_cards_value);

	*deck = card_array[0];
	card_array[0]->prev = NULL;
	for (i = 1; i < list_size; i++)
	{
		card_array[i]->prev = card_array[i - 1];
		card_array[i - 1]->next = card_array[i];
	}
	card_array[list_size - 1]->next = NULL;

	free(card_array);
}

/**
 * compare_cards_kind -  Compares two cards based on their suit.
 *
 * This function is used as a comparison function for `qsort` during
 * the first sorting pass based on suit. It takes two pointers to `deck_node_t`
 * structures as arguments, representing cards in the deck.
 *
 * @a: A pointer to the first card to compare.
 * @b: A pointer to the second card to compare.
 *
 * Return: An integer less than, equal to, or greater than zero,
 * indicating the relative order of the cards:
 * - Negative: If the first card's suit is less than the second card's suit.
 * - Zero: If the first card's suit is equal to the second card's suit.
 * - Positive: If the first card's suit is greater than the second card's suit.
 *
 * Note: This function assumes the `deck.h` header file is included,
 * which defines the `deck_node_t` structure and the `card_t` structure
 * containing the `kind` member for the suit.
 */
int compare_cards_kind(const void *a, const void *b)
{
	const deck_node_t *node1 = *(const deck_node_t **)a;
	const deck_node_t *node2 = *(const deck_node_t **)b;

	return (node1->card->kind - node2->card->kind);
}

/**
 * compare_cards_value - Compares two cards based on their value
 * within the same suit.
 *
 * This function is used as a comparison function for `qsort`
 * during the second sorting pass based on value
 * within each suit. It takes two pointers to `deck_node_t`
 * structures as arguments, representing cards in the deck.
 *
 * @a: A pointer to the first card to compare.
 * @b: A pointer to the second card to compare.
 *
 * Return: An integer less than, equal to, or greater than zero,
 * indicating the relative order of the cards:
 * - Negative: If the first card's value is less than the second card's value.
 * - Zero: If the first card's value is equal to the second card's value.
 * - Positive: If the first card's value is greater than the
 * second card's value.
 *
 * Note: This function uses static arrays for card names and
 * values for efficiency. It also handles cases where
 * the card value is not one of the predefined names
 * ("Ace", "Jack", "King", "Queen").
 * This function assumes the `deck.h` header file is included, which defines
 * the `deck_node_t` structure
 * and the `card_t` structure containing the `value` member for the card value.
 */
int compare_cards_value(const void *a, const void *b)
{
	const deck_node_t *node1 = *(const deck_node_t **)a;
	const deck_node_t *node2 = *(const deck_node_t **)b;

	static char *cards[] = {"Ace", "Jack", "King", "Queen", NULL};
	static int values[] = {0, 11, 12, 13};
	int i = 0, node1_compare_value = -1, node2_compare_value = -1;

	for (i = 0; cards[i]; i++)
	{
		if (_strcmp(cards[i], node1->card->value) == 0)
			node1_compare_value = values[i];
		if (_strcmp(cards[i], node2->card->value) == 0)
			node2_compare_value = values[i];
	}

	if (node1_compare_value == -1)
		node1_compare_value = _atoi(node1->card->value);
	if (node2_compare_value == -1)
		node2_compare_value = _atoi(node2->card->value);

	return (node1_compare_value - node2_compare_value);
}

/**
 * _strcmp - Compares two strings lexicographically.
 *
 * This function compares two null-terminated strings (`str1` and `str2`)
 * and returns an integer indicating their relative ordering.
 *
 * @str1: A pointer to the first string to compare.
 * @str2: A pointer to the second string to compare.
 *
 * Return: An integer value indicating the relative order of the strings:
 * - 0: If the strings are equal.
 * - Negative value: If `str1` is less than `str2` (lexicographically).
 * - Positive value: If `str1` is greater than `str2` (lexicographically).
 *
 * Note: This function does not perform any bounds checking and assumes
 * that the strings are properly null-terminated.
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i;

	if (!str1 && !str2)
		return (0);

	if (!str1 || !str2)
	{
		if (!str1)
			return (-str2[0]);
		else
			return (str1[0]);
	}

	for (i = 0; str1[i] != '\0'; i++)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);

	if (str1[i] == '\0' && str2[i] != '\0')
		return (-str2[i]);

	return (0);
}

/**
 *  _atoi - Converts a string to a long integer.
 *
 * This function attempts to convert a null-terminated string (`str`)
 * to a long integer (`long int`).
 *
 * @str: A pointer to the string to convert.
 *
 * Return: The long integer value extracted from the string,
 * or 0 if the conversion fails.
 *
 * Note:This function does not handle leading or trailing whitespace
 * characters. It also stops conversion upon encountering any non-digit
 * character.
 */
long int _atoi(const char *str)
{
	long int num = 0;
	int i = 0, sign = 1;

	if (!str || *str == '\0')
		return (0);

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else
			break;

		i++;
	}

	return (num * sign);
}
