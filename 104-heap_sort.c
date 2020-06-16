#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: array to sort
 * @size: lenght of array
 */
void heap_sort(int *array, size_t size)
{
	size_t tail;
	int value, i;
	int parents, child_max;

	tail = size - 1;
	while (tail > 0)
	{
		parents = (tail - 1) / 2;
		for (i = parents; i >= 0; i--)
		{
			/* si es el primer padre (posibilidad de tener solo 1 hijo) */
			if (i == parents && tail % 2 != 0)
				child_max = i * 2 + 1;
			else if (array[i * 2 + 1] > array[i * 2 + 2])
				child_max = i * 2 + 1;
			else
				child_max = i * 2 + 2;

			if (array[child_max] > array[i])
			{
				value = array[child_max];
				array[child_max] = array[i];
				array[i] = value;
				/* prevent i-- de for */
				i = parents + 1;
				print_array(array, size);
			}
		}
		/* swap 0 con tail */
		value = array[0];
		array[0] = array[tail];
		array[tail] = value;
		print_array(array, size);
		tail--;
	}
}
