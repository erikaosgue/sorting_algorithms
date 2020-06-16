#include "sort.h"

/**
 * merge_func -  sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array_1: Array of the left
 * @array_2: array of the right
 * @size_1: size of the array_1
 * @size_2: size of the array_2
 * @merge: Pointer of the auxiliar array
 * Return: Pointer of the auxiliar array sorted
 */

int *merge_func(int *array_1, int *array_2, size_t size_1,
size_t size_2, int *merge)
{
	int total_size = 0;
	size_t len_1 = 0, len_2 = 0;
	int i = 0;

	total_size = size_1 + size_2;

	for (i = 0; i < total_size; i++)
	{
		if (len_1 < size_1 && len_2 < size_2)
		{
			if (array_1[len_1] < array_2[len_2])
			{
				merge[i] = array_1[len_1];
				len_1++;
			}
			else
			{
				merge[i] = array_2[len_2];
				len_2++;
			}
			continue;

		}
		if (len_1 == size_1)
		{
			merge[i] = array_2[len_2];
			len_2++;
		}
		else if (len_2 == size_2)
		{
			merge[i] = array_1[len_1];
			len_1++;
		}
	}
	return (merge);

}
/**
 * merge_sort -  sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array: Array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *merge = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	merge = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		merge[i] = 0;
	merge_recursion(array, size, merge);
	free(merge);
}
/**
 * merge_recursion -  sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *
 * @array: Array to sort
 * @size: size of the array
 * @merge: Pointer to the auxiliar array
 * Return: Pointer to the array
 */
int *merge_recursion(int *array, size_t size, int *merge)
{
	int *array_left = NULL;
	int *array_right = NULL;
	int i = 0;

	if (size <= 1)
		return (array);

	i = size / 2;
	array_left = merge_recursion(array, i, merge);
	array_right = merge_recursion(array + i, size - i, merge);
	merge_func(array_left, array_right, i, size - i, merge);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, i);
	printf("[right]: ");
	print_array(array_right, size - i);
	printf("[Done]: ");
	print_array(merge, size);
	for (i = 0; (size_t)i < size; i++)
		array[i] = merge[i];
	return (array);
}
