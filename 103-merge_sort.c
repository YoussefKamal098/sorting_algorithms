#include "sort.h"

void _merge_sort(int *array, int *buffer, size_t left, size_t right);
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right);

/**
 * merge_sort - Sorts an array of integers using the merge sort algorithm.
 *
 * This function is a wrapper for the internal _merge_sort function. It
 * allocates temporary buffer memory, calls _merge_sort to perform the
 * sorting, and then frees the allocated buffer.
 *
 * @array: array Pointer to the array of integers to be sorted.
 * @size: size Size of the array (number of elements).
 *
 * Return: None (void function).
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = (int *)malloc(sizeof(int) * size);

	if (!buffer)
		return;

	_merge_sort(array, buffer, 0, size);

	free(buffer);
}

/**
 * _merge_sort -  Recursive helper function for merge sort algorithm.
 *
 * This function performs the core merge sort logic by dividing the array
 * into halves, recursively sorting them, and then merging the sorted halves
 * back together in sorted order.
 *
 * @array: array Pointer to the array of integers to be sorted.
 * @buffer: buffer Pointer to the temporary buffer for merging.
 * @left: left Index of the leftmost element in the current sub-array.
 * @right: right Index of the rightmost element + 1 (exclusive) in
 * the current sub-array.
 */
void _merge_sort(int *array, int *buffer, size_t left, size_t right)
{
	size_t mid;

	if (right <= left + 1)
		return;

	mid = left + (right - left) / 2;

	_merge_sort(array, buffer, left, mid);
	_merge_sort(array, buffer, mid, right);

	merge(array, buffer, left, mid, right);
}

/**
 * merge - Merges two sorted sub-arrays into a single sorted sub-array.
 *
 * This function takes two sorted sub-arrays within the original array and
 * merges them into a single sorted sub-array in the original array. It uses
 * a temporary buffer to hold elements during the merging process.
 *
 * The function prints debugging information during the merge process,
 * which can be helpful for visualization and understanding the algorithm.
 * (Note: This printing can be disabled if desired.)
 *
 * @array: array Pointer to the array of integers containing sub-arrays.
 * @buffer: buffer Pointer to the temporary buffer for merging.
 * @left: left Index of the leftmost element in the first sub-array.
 * @mid: mid Index of the element separating the two sub-arrays
 * (exclusive for left sub-array).
 * @right: right Index of the rightmost element + 1 (exclusive)
 * in the second sub-array.
 */
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
	size_t i, j, low = left, high = mid;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = 0; low < mid || high < right; i++)
	{
		if (high >= right || (low < mid && array[low] < array[high]))
			buffer[i] = array[low++];
		else
			buffer[i] = array[high++];
	}

	for (i = left, j = 0; i < right; i++, j++)
		array[i] = buffer[j];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
