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
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description:
 * This function implements the Bubble Sort algorithm to
 * sort an array of integers in
 * ascending order. It compares adjacent elements and
 * swaps them if they are in the wrong order.
 * The process is repeated until the array is sorted.
 * Additionally, the intermediate steps of
 * the sorting process are printed using the `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 * - The size of the array must be greater than or equal to 2 for
 * the sorting to take place.
 *
 * Example:
 * Given an array: {4, 2, 7, 1, 9, 3, 5}
 * After applying bubble_sort, the array becomes: {1, 2, 3, 4, 5, 7, 9}
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}
