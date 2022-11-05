#include "sort.h"

/**
 * quick_sort - sort the array using quick sort
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recurssion(array, 0, size - 1, size);
}

/**
 * quick_sort_recurssion - break the array into sub arrays
 * @array: the array to break into sub arrays
 * @low: the left most index of the array
 * @high: the right most index of the array
 * @size: the size of the array
 *
 * Return - Nothing
 */
void quick_sort_recurssion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quick_sort_recurssion(array, low, pivot_index - 1, size);
		quick_sort_recurssion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - partition the array
 * @array: the array to partition
 * @low: the left most index of the array
 * @high: the right most index of the array
 * @size: the size of the array
 *
 * Return: the index of the pivote point
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot_value;

	pivot_value = array[high];

	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			swap(&array[j], &array[i]);
		}
	}

	i++;
	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}

/**
 * swap - swap the element of the array
 * @x: the first element
 * @y: the second element
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
