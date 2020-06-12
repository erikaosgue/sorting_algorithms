#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: lenght of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 1;
	int prev = 0;
	int trigger = 0;
	int sorting = 1;

	if (array == NULL || size < 1)
		return;

	if (size == 1)
		printf("%d\n", array[0]);

	while (sorting)
	{
		trigger = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				prev = array[i - 1];
				array[i - 1] = array[i];
				array[i] = prev;
				print_array(array, size);
				trigger = 1;
			}
			if (trigger == 0 && i == size - 1)
				sorting = 0;
		}
	}
}
