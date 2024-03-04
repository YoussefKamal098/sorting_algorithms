#include "sort.h"

void _quick_sort_hoare(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);
void swap(int *a, int *b);

/**
 * quick_sort_hoare - Sorts an array of integers using the Hoare
 * partition scheme.
 *
 * This function performs the Hoare partition scheme, recursively dividing
 * the array into subarrays and sorting them using a pivot element.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 *
 * Note: The input array must not be NULL, and the size should be at least 2.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	_quick_sort_hoare(array, size, 0, size - 1);
}

/**
 * _quick_sort_hoare - Helper function for the Hoare partition scheme.
 *
 * This function recursively sorts a subarray of integers using the Hoare
 * partition scheme.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 * @left: left Starting index of the subarray.
 * @right: right Ending index of the subarray.
 *
 * Note: The input array must not be NULL, and the indices should be valid.
 */
void _quick_sort_hoare(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left >= right)
		return;

	pivot = hoare_partition(array, size, left, right);

	_quick_sort_hoare(array, size, left, pivot - 1);
	_quick_sort_hoare(array, size, pivot, right);
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme.
 *
 * This function partitions the array into two segments based on a pivot,
 * arranging elements such that elements smaller than the pivot are on the
 * left, and elements greater than the pivot are on the right.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 * @left: left Starting index of the partition.
 * @right: right Ending index of the partition.
 *
 * Note: The input array must not be NULL, and the indices should be valid.
 *
 * Return: The index of the pivot after partitioning.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];

	left--, right++;

	while (left < right)
	{
		do {
			left++;
		} while (array[left] < pivot);

		do {
			right--;
		} while (array[right] > pivot);

		if (left < right)
		{
			swap(&array[left], &array[right]);
			print_array(array, size);
		}
	}

	return (left);
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
