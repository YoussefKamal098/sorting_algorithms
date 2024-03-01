#include "sort.h"

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
 *
 * Example:
 * Given a doubly linked list: 4 <-> 2 <-> 7 <-> 1 <-> 9 <-> 3 <-> 5
 * After applying insertion_sort_list, the list becomes:
 * 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 7 <-> 9
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
