#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 *		in ascending order using the Selection sort algorithm
 * @array: given array of integers
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}

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
