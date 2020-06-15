#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: array to sort
 * @size: lenght of array
 */
void counting_sort(int *array, size_t size)
{
	int *counter_array, *backup_array;
	int max = 0, counter = 0, i, n;

	if (array == NULL || size < 2)
		return;
	backup_array = malloc(sizeof(int) * size);
	/* max is the largest number of the array */
	for (i = 0; (size_t)i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	} max++;
	/* create an array of size 'max' and set values to 0 */
	counter_array = malloc(sizeof(int) * max);
	for (i = 0; i < max; i++)
		counter_array[i] = 0;
	/* Take a count array to store the count of each unique object */
	for (i = 0; (size_t)i < size; i++)
	{
		counter_array[array[i]] += 1;
		/* aprovechamos para hacer la backup_array */
		backup_array[i] = array[i];
	}
	/* Modify the count array such that each element at each index */
	/* stores the sum of previous counts. */
	for (i = 0; i < max; i++)
	{
		counter += counter_array[i];
		counter_array[i] = counter;
	}
	print_array(counter_array, max);
	/* The modified count array indicates the position */
	/* of each object in the output sequence */
	for (i = size - 1; i >= 0; i--)
	{
		n = backup_array[i];
		counter_array[n] -= 1;
		array[counter_array[n]] = backup_array[i];
	}
	free(counter_array);
}
