#include "sort.h"

void _bitonic_sort(int *array, size_t size, size_t start,
		   size_t sequence_size, int flow);
void bitonic_merge(int *array, size_t start, size_t sequence_size, int flow);
void swap(int *a, int *b);

/**
 * bitonic_sort - Sorts an array using the Bitonic Sort algorithm.
 *
 * This function sorts the elements of an array in ascending order
 * using the Bitonic Sort algorithm. The function checks for valid
 * input parameters and then calls the internal Bitonic Sort function.
 *
 * @array: array Pointer to the array to be sorted.
 * @size: size Number of elements in the array
 *
 * Note:The array is sorted in-place. The input array must not be NULL,
 * and the size should be at least 2.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_bitonic_sort(array, size, 0, size, UP);
}

/**
 * bitonic_sort - Performs the recursive Bitonic Sort operation.
 *
 * This function is used internally for recursive Bitonic Sort.
 * It divides the array into two halves, sorts each half in the
 * specified order, and then performs a Bitonic Merge operation
 * to combine them in the desired order.
 *
 * @array: array Pointer to the array to be sorted.
 * @size: size Number of elements in the array.
 * @start: start Starting index of the current sequence.
 * @sequence_size: Number of elements in the current sequence.
 * @flow: flow Order of sorting (UP or DOWN).
 *
 * Note: This function is called recursively until the sequence size is 1.
 * The input array must not be NULL, and the sequence size
 * should be at least 2.
 */
void _bitonic_sort(int *array, size_t size, size_t start,
		   size_t sequence_size, int flow)
{
	size_t cut;
	char *dir;

	if (sequence_size <= 1)
		return;

	cut = sequence_size / 2;
	dir = flow == UP ? "UP" : "DOWN";

	printf("Merging [%lu/%lu] (%s):\n", sequence_size, size, dir);
	print_array(array + start, sequence_size);

	_bitonic_sort(array, size, start, cut, UP);
	_bitonic_sort(array, size, start + cut, cut, DOWN);

	bitonic_merge(array, start, sequence_size, flow);

	printf("Result [%lu/%lu] (%s):\n", sequence_size, size, dir);
	print_array(array + start, sequence_size);
}

/**
 * bitonic_merge - Performs the Bitonic Merge operation.
 *
 * This function is used to merge two sequences of the Bitonic Sort
 * in the specified order (UP or DOWN). It compares and swaps elements
 * in the given sequences to ensure they are in the desired order.
 *
 * @array: array Pointer to the array being sorted.
 * @start: start Starting index of the current sequence.
 * @sequence_size: Number of elements in the current sequence.
 * @flow: flow Order of sorting (UP or DOWN).
 *
 * Note: This function is called recursively until the sequence size is 1.
 * The input array must not be NULL, and the sequence size
 * should be at least 2.
 */
void bitonic_merge(int *array, size_t start, size_t sequence_size, int flow)
{
	size_t jump = sequence_size / 2, i;

	if (sequence_size <= 1)
		return;

	for (i = start; i < start + jump; i++)
	{
		if ((flow == UP && array[i] > array[i + jump]) ||
		    (flow == DOWN && array[i] < array[i + jump]))
			swap(&array[i], &array[i + jump]);
	}

	bitonic_merge(array, start, jump, flow);
	bitonic_merge(array, start + jump, jump, flow);
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
