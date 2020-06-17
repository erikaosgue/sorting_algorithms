#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: Array of integers to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	recursion(array, size, array, size);
}

/**
 * recursion - sorts an array of integers in ascending
 * order using Recursion
 *
 * @array: Portion of the array to be sort
 * @size: size of the array
 * @full_array: The complete array
 * @full_size: The size of the full_array
 */
void recursion(int *array, size_t size, int *full_array, size_t full_size)
{
	int *pivot = NULL;
	size_t j = 0;
	int i = -1, value = 0;

	if (array == NULL || size <= 1)
		return;

	pivot = &array[size - 1];
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= *pivot)
		{
			i++;
			if (&array[i] != &array[j])
			{
				value = array[i];
				array[i] = array[j];
				array[j] = value;
				print_array(full_array, full_size);
			}
		}
	}
	i++;
	if (&array[i] != pivot)
	{
		value = array[i];
		array[i] = *pivot;
		*pivot = value;
		print_array(full_array, full_size);
	}
	recursion(&array[0], i, full_array, full_size);
	recursion(&array[i + 1], size - (i + 1), full_array, full_size);
}
