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
 * hoare_partition - a function that splits the array after getting
 *		the pivot
 * @array: given array to sort
 * @start: start index to begin with
 * @end: end index of the array
 * @size: size of the array
 *
 * Return: the pivot location
*/

int hoare_partition(int *array, int start, int end, size_t size)
{
	int pivot, above, below;

	pivot = array[end];
	for (above = start - 1, below = end + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - a recursive function that sorts the array
 *		recursively
 * @array: given array to sort
 * @start: start index to begin with
 * @end: end index of the array
 * @size: size of the array
*/

void hoare_sort(int *array, int start, int end, size_t size)
{
	int parted;

	if (end <= start)
		return;
	parted = hoare_partition(array, start, end, size);
	hoare_sort(array, start, parted - 1, size);
	hoare_sort(array, parted, end, size);
}

/**
 * quick_sort_hoare - function that sorts an array of integers in
 *		ascending order using the Quick sort algorithm
 * @array: given array
 * @size: size of the array
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, size - 1, size);
}
