#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: array to sort
 * @size: lenght to array
 */
void selection_sort(int *array, size_t size)
{
	int *current = NULL;
	int *checker = NULL;
	int *min = NULL;
	int value_current;
	size_t i, j;

	if (array == NULL || size == 0)
		return;

	current = array;
	checker = array;

	for (i = 0; i < size; i++)
	{
		current = &array[i];
		min = &array[i];
		checker = &array[i];

		for (j = i; j < size; j++)
		{
			if (*checker < *min)
				min = checker;
			checker++;
		}

		if (current != min)
		{
			value_current = *current;
			*current = *min;
			*min = value_current;
			print_array(array, size);
		}
	}
}
