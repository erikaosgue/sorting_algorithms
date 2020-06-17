#include "sort.h"
/**
 * num_digits - FInd the number of digits of a number
 * @number: Number to find the digits
 * Return: An integer with the number of digits
 */
int num_digits(int number)
{
	int num_dig = 1;

	while (number / 10)
	{
		num_dig++;
		number = number / 10;
	}
	return (num_dig);
}

/**
 * which_number - find the number to the digit specify
 * @number: number to find digit
 * @digit: digit we want to get from the number
 * @size: Size of the number
 * Return: An integer with the digit we want
 */
int which_number(int number, int digit, int size)
{
	int i = 0;

	while (number && i < size - digit)
	{
		number = number / 10;
		i++;
	}
	return (number %= 10);
}

/**
 * max_number - find the max number in the array
 * @array: Pointer to the array
 * @size: size of the array
 * Return: An integer with the biggest number
 */
int max_number(int *array, int size)
{
	int max = 0, i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int num_dig = 0, count = 0, size_num = 0, num_idx;
	int *arr_sum = NULL, *arr_sorting = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	count = max_number(array, size);
	size_num = num_dig = num_digits(count);
	arr_sum = malloc(sizeof(int) * 10);
	arr_sorting = malloc(sizeof(int) * 10);
	while (num_dig)
	{ count = 0;
		/* initialize both arrays in 0 */
		for (i = 0; i < 10; i++)
			arr_sum[i] = 0, arr_sorting[i] = 0;
		/* add 1 for each coincidence of a number in the idx */
		for (i = 0; i < size; i++)
		{ num_idx = which_number(array[i], num_dig, size_num);
			arr_sum[num_idx] += 1;
		}
		/* sum all num until the actual num */
		for (i = 0; i < 10; i++)
		{ count += arr_sum[i];
			arr_sum[i] = count;
		}
		/* go from last to first in the original array */
		for (i = size - 1; (int)i >= 0; i--)
		{ num_idx = which_number(array[i], num_dig, size_num);
			arr_sum[num_idx] -= 1;
			arr_sorting[arr_sum[num_idx]] = array[i];
		}
		/* put back the array sorted in the original */
		for (i = 0; i < size; i++)
			array[i] = arr_sorting[i];
		print_array(array, size);
		num_dig--;
	} free(arr_sum);
	free(arr_sorting);
}
