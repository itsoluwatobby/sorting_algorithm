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
 * partition - a function that splits the array after getting
 *		the pivot
 * @array: given array to sort
 * @start: start index to begin with
 * @end: end index of the array
 * @size: size of the array
 *
 * Return: the pivot location
*/

int partition(int *array, int start, int end, size_t size)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - a recursive function that sorts the array
 *		recursively
 * @array: given array to sort
 * @start: start index to begin with
 * @end: end index of the array
 * @size: size of the array
*/

void lomuto_sort(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;
	pivot = partition(array, start, end, size);
	lomuto_sort(array, start, pivot - 1, size);
	lomuto_sort(array, pivot + 1, end, size);
}

/**
 * quick_sort - function that sorts an array of integers in
 *		ascending order using the Quick sort algorithm
 * @array: given array
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}
