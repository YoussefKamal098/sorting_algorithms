#include "sort.h"

int swap_right(listint_t **list, listint_t **start, listint_t **end);
int swap_left(listint_t **list, listint_t **start, listint_t **end);
void swap_with_next_node(listint_t **list, listint_t *node);
void swap_with_pre_node(listint_t **list, listint_t *node);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 * Description:
 * This function implements the Cocktail Shaker sort algorithm to
 * sort a doubly linked list of integers. It repeatedly traverses
 * the list in both directions, comparing and swapping adjacent elements,
 * until the list is fully sorted.
 *
 * Note:
 * - The input pointer `list` must point to a valid doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = *list;

	while (end->next)
		end = end->next;

	while (swapped)
	{
		swapped = swap_right(list, &start, &end);
		swapped = swap_left(list, &start, &end);
	}
}

/**
 * swap_right - Swaps elements in the rightward direction.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 * @start: Pointer to the starting node of the current swapping direction.
 * @end: Pointer to the end node of the current swapping direction.
 *
 * Description:
 * This function swaps adjacent elements in the rightward
 * direction starting from the given start node up to the end node.
 *
 * Note:
 * - The input pointers `list`, `start`, and `end` must be valid.
 *
 * Return: 1 if any swaps occurred, 0 otherwise.
 */
int swap_right(listint_t **list, listint_t **start, listint_t **end)
{
	listint_t *curr = *start;
	int swapped = 0;

	if (!list || !*list || !*start || !*start || !end || !*end)
		return (0);

	while (curr != *end)
	{
		if (curr->next && curr->n > curr->next->n)
		{
			swap_with_next_node(list, curr);
			if (curr == *start)
				*start = curr->prev;

			swapped = 1;

			print_list((const listint_t *)(*list));
		}
		else if (curr->prev != *end)
			curr = curr->next;
		else
			break;
	}

	if (curr->prev != *end)
		*end = (*end)->prev;

	return (swapped);
}

/**
 * swap_left - Swaps elements in the leftward direction.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 * @start: Pointer to the starting node of the current swapping direction.
 * @end: Pointer to the end node of the current swapping direction.
 *
 * Description:
 * This function swaps adjacent elements in the leftward
 * direction starting from the given end node up to the start node.
 *
 * Note:
 * - The input pointers `list`, `start`, and `end` must be valid.
 *
 * Return: 1 if any swaps occurred, 0 otherwise.
 */
int swap_left(listint_t **list, listint_t **start, listint_t **end)
{
	listint_t *curr = *end;
	int swapped = 0;

	if (!list || !*list || !*start || !*start || !end || !*end)
		return (0);

	while (curr != *start)
	{
		if (curr->prev && curr->n < curr->prev->n)
		{
			swap_with_pre_node(list, curr);
			if (curr == *end)
				*end = curr->next;

			swapped = 1;

			print_list((const listint_t *)(*list));
		}
		else if (curr->next != *start)
			curr = curr->prev;
		else
			break;
	}

	if (curr->next != *start)
		*start = (*start)->next;

	return (swapped);
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
