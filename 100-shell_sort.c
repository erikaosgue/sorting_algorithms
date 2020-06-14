#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to sort
 * @size: lenght of array
 */
void shell_sort(int *array, size_t size)
{
	int _size = size;
	int interval = 0;
	int i, current, value;

	if (array == NULL || size < 2)
		return;

	while (interval < (_size / 3))
		interval = interval * 3 + 1;

	if (size == 2)
		interval = 1;

	/* interval will decrease with the same pattern */
	while (interval > 0)
	{
		/* pass */
		for (i = interval; i < _size; i++)
		{
			current = i;
			/* check for out of range */
			while (current - interval >= 0)
			{
				/* compare values */
				if (array[current] < array[current - interval])
				{
					value = array[current];
					array[current] = array[current - interval];
					array[current - interval] = value;
				}
				else
					break;
				current -= interval;
			}
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
