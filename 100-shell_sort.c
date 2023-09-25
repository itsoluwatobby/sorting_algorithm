#include "sort.h"

/**
 * swap_ints - Swap two values in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
*/

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort -  function that sorts an array of integers in
 *		ascending order using the Shell sort algorithm,
 *		using the Knuth sequence
 * @array: given array
 * @size: size of array
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 0; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = 1;

			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
