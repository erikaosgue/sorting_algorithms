#include "sort.h"
/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: Pointer to the array
 * @size: size of the array
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	recursion_hoare(array, size, array, size);
}
/**
 * recursion_hoare - Quick sort using hoare partition
 * @array: Pointer to the sub_array
 * @size: size of the sub_array
 * @full_array: Pointer to the full_array
 * @full_size: size of the full_array
 */
void recursion_hoare(int *array, int size, int *full_array, int full_size)
{
	int pivot = 0;
	int j, k = 1;
	int i = 0, value = 0;

	if (array == NULL || size <= 1)
		return;

	j = size - 1;
	pivot = array[size - 1];
	while (k)
	{
		while (array[i] < pivot && i != size - 1)
		{
			if (i < size - 1)
				i++;
		}
		while (array[j] > pivot && j != 0)
		{
			if (j > 0)
				j--;
		}
		if (i >= j)
		{
			if (j != size - 1)
				k = j + 1;
			else
				k = j;
			recursion_hoare(&array[0], k, full_array, full_size);
			recursion_hoare(&array[k], size - j - 1, full_array, full_size);
			k = 0;
			break;
		}
		value = array[i];
		array[i] = array[j];
		array[j] = value;
		j--;
		i++;
		print_array(full_array, full_size);
	}
}
