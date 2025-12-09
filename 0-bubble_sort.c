#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: Array to sort
 * @size: Number of elements
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
