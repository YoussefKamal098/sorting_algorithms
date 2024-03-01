#include "sort.h"

void _quick_sort(int *array, size_t left, size_t right, size_t size);
size_t Lomuto_partition(int *array, size_t left, size_t right, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @size: Size of the array.
 *
 * Description:
 * This function implements the Quick Sort algorithm using the Lomuto
 * partition scheme. It recursively divides the array into subarrays
 * and sorts them in-place. The intermediate steps of the sorting process
 * are printed using the `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursively sorts subarrays using the Quick Sort algorithm.
 *
 * @array: Pointer to the first element of the array.
 * @left: Index of the leftmost element of the array or subarray.
 * @right: Index of the rightmost element of the array or subarray.
 * @size: Size of the array.
 *
 * Description:
 * This function is a helper function for the Quick Sort algorithm.
 * It recursively divides the array into subarrays and sorts them in-place.
 * The intermediate steps of the sorting process are printed using the
 * `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 */
void _quick_sort(int *array, size_t left, size_t right, size_t size)
{
	size_t pivot;

	if ((int)left >= (int)right)
		return;

	pivot = Lomuto_partition(array, left, right, size);

	_quick_sort(array, left, pivot - 1, size);
	_quick_sort(array, pivot + 1, right, size);
}

/**
 * Lomuto_partition - Partitions an array using the Lomuto partition scheme.
 *
 * @array: Pointer to the first element of the array.
 * @left: Index of the leftmost element of the array or subarray.
 * @right: Index of the rightmost element of the array or subarray.
 * @size: Size of the array.
 *
 * Description:
 * This function implements the Lomuto partition scheme, which is used as part
 * of the Quick Sort algorithm. It selects a pivot element from the array and
 * partitions the array into two parts: elements less than
 * the pivot and elements greater than or equal to the pivot.
 * The intermediate steps of the partitioning
 * process are printed using the `print_array` function.
 *
 * Note:
 * - The input array must be a valid array of integers.
 *
 * Return:
 * The index of the pivot element after the partitioning process.
 */
size_t Lomuto_partition(int *array, size_t left, size_t right, size_t size)
{
	int pivot = array[right];
	size_t high, low;

	for (low = high = left; low < right; low++)
	{
		if (array[low] < pivot)
		{
			if (low > high)
			{
				swap(&array[high], &array[low]);
				print_array(array, size);
			}

			high++;
		}
	}

	if (array[high] > pivot)
	{
		swap(&array[high], &array[right]);
		print_array(array, size);
	}

	return (high);
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
