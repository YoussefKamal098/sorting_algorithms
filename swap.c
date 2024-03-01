#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description:
 * This function swaps the values of the integers pointed to by `a` and `b`.
 *
 * Note:
 * - The input pointers `a` and `b` must be valid pointers to integers.
 */
void swap(int *a, int *b)
{
	int tmp;

	if (!a || !b)
		return;
	tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * swap_with_next_node - Swaps a node with its next node
 * in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 * @node: Pointer to the node to be swapped.
 *
 * Description:
 * This function swaps the given node with its next node in
 * a doubly linked list. It updates the pointers accordingly to
 * maintain the integrity of the linked list.
 *
 * Note:
 * - The input pointers `list` and `node` must be valid.
 * - The linked list must be doubly linked.
 * - The given node and its next node must be part of the linked list.
 */
void swap_with_next_node(listint_t **list, listint_t *node)
{
	listint_t *next_node;

	if (!list || !*list || !node || !node->next)
		return;

	next_node = node->next;

	node->next = next_node->next;
	next_node->prev = node->prev;

	if (node->prev)
		node->prev->next = next_node;
	else
		*list = next_node;

	if (next_node->next)
		next_node->next->prev = node;

	node->prev = next_node;
	next_node->next = node;
}
