#include "sort.h"

int get_max(int *array, size_t size);
int get_min(int *array, size_t size);

/**
 * counting_sort - Sorts an array of integers using the counting
 * sort algorithm.
 *
 * This function performs counting sort on the given array of integers.
 * It allocates memory for a counter array, sorts the input array, and prints
 * the intermediary results during the sorting process.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, range;
	int max, min;
	int *counter, *sorted_array;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	min = get_min(array, size);

	range = min >= 0 ? max + 1 : max - min + 1;
	min = min >= 0 ? 0 : min;

	counter = (int *)malloc(sizeof(int) * range);

	if (!counter)
		return;

	sorted_array = (int *)malloc(sizeof(int) * size);

	if (!sorted_array)
	{
		free(counter);
		return;
	}

	_memset((char *)counter, 0, range * sizeof(int));

	for (i = 0; i < size; i++)
		counter[array[i] - min] += 1;

	for (i = 1; i < range; i++)
		counter[i] += counter[i - 1];

	print_array(counter, range);

	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted_array[counter[array[i] - min] - 1] = array[i];
		counter[array[i] - min] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(counter);
	free(sorted_array);
}

/**
 * get_max - Finds the maximum value in an array of integers.
 *
 * This function iterates through the given array to find the maximum value.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	size_t i = 0;
	int max;

	if (!array)
		return (0);

	max = array[0];

	for (i = 0; i < size; i++)
		if (max < array[i])
			max = array[i];
	return (max);
}

/**
 * get_min - Finds the minimum value in an array of integers.
 *
 * This function iterates through the given array to find the minimum value.
 *
 * @array: array Pointer to the array of integers.
 * @size: size Size of the array.
 * Return: The minimum value in the array.
 */
int get_min(int *array, size_t size)
{
	size_t i = 0;
	int min;

	if (!array)
		return (0);

	min = array[0];

	for (i = 0; i < size; i++)
		if (min > array[i])
			min = array[i];
	return (min);
}
