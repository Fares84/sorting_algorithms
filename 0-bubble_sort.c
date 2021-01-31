#include "sort.h"

/**
 *bubble_sort - function that sorts an array of integers in ascending order
 *@array: array to be sort
 *@size: array size
 *Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, switched_int;

	if (size <= 1 || !array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				switched_int = array[j];
				array[j] =  array[j + 1];
				array[j + 1] =  switched_int;
				print_array(array, size);
			}
		}
	}
}
