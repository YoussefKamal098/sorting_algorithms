#include "sort.h"

int get_max(int *array, int size);
void counting_digit_sort(int *array, int exp, int *buffer, size_t size);

/**
 * radix_sort -  Performs radix sort on an array of integers.
 *
 * This function sorts the elements of an array using the radix sort algorithm.
 *
 * @array: array Pointer to the array to be sorted.
 * @size: size Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int *buffer, exp, max;

	if (!array || size < 2)
		return;

	buffer = (int *)malloc(sizeof(int) * size);

	if (!buffer)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp < 0; exp *= 10)
	{
		counting_digit_sort(array, exp, buffer, size);
		print_array(array, size);
	}

	free(buffer);
}

/**
 * get_max -  Finds the maximum value in an array of integers.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Number of elements in the array.
 * Return: The maximum value in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * counting_digit_sort - Performs counting sort on an array based
 * on a specific digit.
 *
 * This function is part of the radix sort algorithm and sorts the elements of
 * the array based on the specified digit (exp).
 *
 * @array: array Pointer to the array to be sorted.
 * @exp: exp The digit position to consider for sorting.
 * @buffer: buffer Temporary buffer array for intermediate storage.
 * @size: size Number of elements in the array.
 */
void counting_digit_sort(int *array, int exp, int *buffer, size_t size)
{
	int counter[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		counter[(array[i] / exp) % 10] += 1;

	for (i = 1; i < 10; i++)
		counter[i] += counter[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[counter[(array[i] / exp) % 10] - 1] = array[i];
		counter[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}
