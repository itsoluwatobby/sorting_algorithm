#include "sort.h"

/**
 * _max - function that gets the maximum value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: maximum integer in the array.
*/

int _max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_count_sort - funtion that sorts the significant
 *			digits of an array of integers in ascending
 *			order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
*/

void radix_count_sort(int *array, size_t size, int sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];
}

/**
 * radix_sort - function sorts an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: given array of integers.
 * @size: size of array.
*/

void radix_sort(int *array, size_t size)
{
	int max, sig, *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	max = _max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
