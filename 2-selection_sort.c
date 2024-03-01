#include "sort.h"

void swap(int *a, int *b);

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 *
 * Description:
 * This function implements the Selection Sort algorithm to sort an array
 * of integers in ascending order. It iterates through the array, selects
 * the minimum element, and swaps it with the first unsorted element. The
 * intermediate steps of the sorting process are printed using the
 * `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int swapped, min_value;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		min_value = array[i];
		swapped = 0;
		for (j = i + 1; j < size; j++)
		{
			if (min_value > array[j])
			{
				min_index = j;
				min_value = array[j];
				swapped = 1;
			}
		}

		if (swapped)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
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
