#include "sort.h"

/**
 * swap_ints - Swap two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index (pivot index)
 * @size: Size of the full array (for printing)
 *
 * Return: Index of pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;

for (j = low; j < high; j++)
{
	if (array[j] < pivot)
	{
		i++;
		if (i != j)
		{
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

if (array[i + 1] != array[high])
{
	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);
}
return (i + 1);
}

/**
 * quick_sort_recursive - Recursively apply quicksort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Full size of array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int p;

if (low < high)
{
	p = lomuto_partition(array, low, high, size);
	quick_sort_recursive(array, low, p - 1, size);
	quick_sort_recursive(array, p + 1, high, size);
}
}

/**
 * quick_sort - Sorts array using Quick sort (Lomuto scheme)
 * @array: Array of integers
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
	return;

quick_sort_recursive(array, 0, size - 1, size);
}
