#include "sort.h"

/**
 * _memset-  Sets each byte in an array to a specified value.
 *
 * This function fills the first `size` bytes of the array
 * with the specified `byte`.
 *
 * @array: array Pointer to the array of characters.
 * @byte: byte The value to set each byte to.
 * @size: size Number of bytes to set.
 * Return: Pointer to the modified array.
 */
char *_memset(char *array, char byte, size_t size)
{
	size_t i;

	if (!array)
		return (array);

	for (i = 0; size > 0; i++, size--)
		array[i] = byte;

	return (array);
}
