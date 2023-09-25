#include "sort.h"

/**
 * merge_arr - Sort a subarray of integers.
 * @subarr: array of an array of integers to sort.
 * @buffer: buffer to store the sorted subarray.
 * @start: start index of the array.
 * @middle: middle index of the array.
 * @end: last index of the array.
*/

void merge_arr(int *subarr, int *buffer, size_t start, size_t middle,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + start, middle - start);

	printf("[right]: ");
	print_array(subarr + middle, end - middle);

	for (i = start, j = middle; i < middle && j < end; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < middle; i++)
		buffer[k++] = subarr[i];
	for (; j < end; j++)
		buffer[k++] = subarr[j];
	for (i = start, k = 0; i < end; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + start, end - start);
}

/**
 * merge_recursive - function that mplements the merge sort
 *		algorithm through recursion.
 * @subarr: array of an array of integers to sort.
 * @buffer: buffer to store the sorted result.
 * @start: start index of the subarray.
 * @end: last back index of the subarray.
*/

void merge_recursive(int *subarr, int *buffer, size_t start, size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		merge_recursive(subarr, buffer, start, middle);
		merge_recursive(subarr, buffer, middle, end);
		merge_arr(subarr, buffer, start, middle, end);
	}
}

/**
 * merge_sort - function that sorts an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: given array.
 * @size: size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
*/

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_recursive(array, buffer, 0, size);

	free(buffer);
}
