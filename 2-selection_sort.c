#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 *		in ascending order using the Selection sort algorithm
 * @array: given array of integers
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}

		temp = array[i];
		array[i] = array[min];
		array[min] = temp;

		print_array(array, size);
	}
}
