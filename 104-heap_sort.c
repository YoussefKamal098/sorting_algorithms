#include "sort.h"

void heapify(int *array, size_t boundary, size_t parent, size_t size);
void swap(int *a, int *b);

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using heap sort algorithm.
 *
 * This function implements the heap sort algorithm, a comparison-based sorting
 * algorithm that involves building a heap data structure within the array,
 * iteratively extracting the maximum element (root), and placing it at the end
 * of the sorted portion of the array.
 *
 * @array: array Pointer to the array of integers to be sorted.
 * @size: size Size of the array (number of elements).
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2 - 1; (int)i >= 0; i--)
		heapify(array, size - 1, i, size);

	for (i = size - 1; i >= 1; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i - 1, 0, size);
	}
}

/**
 *  heapify -  Maintains the heap property for a given subtree within an array.
 *
 * This function ensures the heap property is maintained for a subtree rooted
 * at the given parent index within the array. It compares the parent with its
 * children and swaps elements if necessary to maintain the max-heap property.
 *
 * @array: array Pointer to the array containing the heap.
 * @boundary: boundary Index of the last element in the valid heap portion.
 * @parent: parent Index of the parent node for which the heap
 * property is checked.
 * @size: size Size of the whole array
 */
void heapify(int *array, size_t boundary, size_t parent, size_t size)
{
	size_t left_child = parent * 2 + 1;
	size_t right_child = parent * 2 + 2;
	size_t smallest = parent;

	if (left_child <= boundary && array[smallest] < array[left_child])
		smallest = left_child;

	if (right_child <= boundary && array[smallest] < array[right_child])
		smallest = right_child;

	if (smallest != parent)
	{
		swap(&array[parent], &array[smallest]);
		print_array(array, size);
		heapify(array, boundary, smallest, size);
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
