#include "sort.h"

void swap(int *a, int *b);
void swap_with_pre_node(listint_t **list, listint_t *node);

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 * Description:
 * This function implements the Insertion Sort algorithm to sort
 * a doubly linked list
 * of integers in ascending order. It iterates through the list,
 * moving each unsorted
 * element into its correct position relative to the sorted elements.
 * The intermediate steps of the sorting process are printed using the
 * `print_list` function.
 *
 * Note:
 * - The input list must be a valid doubly linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		while (prev->prev && prev->n < prev->prev->n)
		{
			swap_with_pre_node(list, prev);
			print_list((const listint_t *)(*list));
		}
	}
}

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
 * swap_with_pre_node - Swaps a node with its previous node
 * in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 * @node: Pointer to the node to be swapped.
 *
 * Description:
 * This function swaps the given node with its previous node in a
 * doubly linked list. It updates the pointers accordingly to maintain
 * the integrity of the linked list.
 *
 * Note:
 * - The input pointers `list` and `node` must be valid.
 * - The linked list must be doubly linked.
 * - The given node must be part of the linked list.
 *
 */
void swap_with_pre_node(listint_t **list, listint_t *node)
{
	listint_t *pre_node;

	if (!list || !*list || !node || !node->prev)
		return;

	pre_node = node->prev;

	pre_node->next = node->next;
	node->prev = pre_node->prev;

	if (node->next)
		node->next->prev = pre_node;

	if (pre_node->prev)
		pre_node->prev->next = node;
	else
		*list = node;

	pre_node->prev = node;
	node->next = pre_node;
}
