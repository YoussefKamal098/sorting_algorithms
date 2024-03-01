#include "sort.h"

size_t get_max_gap(size_t size);

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell Sort algorithm using the Knuth sequence.
 *
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 *
 * Description:
 * This function implements the Shell Sort algorithm, which is an extension
 * of the insertion sort algorithm. It sorts the elements of the array by
 * comparing elements that are distant from each other. The intermediate steps
 * of the sorting process are printed using the `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (!array || size < 2)
		return;

	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
				swap(&array[j - gap], &array[j]);
		}

		print_array(array, size);
	}
}

/**
 * get_max_gap - Calculates the initial maximum gap for the Shell
 * Sort algorithm using the Knuth sequence.
 *
 * @size: Size of the array.
 *
 * Description:
 * This function calculates the initial maximum gap for the Shell Sort
 * algorithm based on the size of the array. The maximum gap is determined
 * using the formula: gap = 3 * gap + 1, and the function
 * returns (gap - 1) / 3.
 *
 * Note:
 * - The input size must be a valid size of the array.
 *
 * Return: The initial maximum gap for Shell Sort.
 */
size_t get_max_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}

	return ((gap - 1) / 3);
}
