#include "sort.h"

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

/**
 * lomuto_sort - a recursive function that sorts the array
 *			recursively
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
	int pivot;
	int temp, j, i;

	pivot = array[end];
	i = start - 1;
	for (j = start;  j <= end - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;

	print_array(array, size);

	return (i);
}
