#include "sort.h"

/**
 *void selection_sort - function that sorts an array of integers in ascending
 *order
 *@array: an array of integers
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, goThrough, minIndex, swap;

	if (!array || size <= 1)
		return;
	while (i + 1 < size)
	{
		minIndex = i;
		goThrough = i + 1;
		while (goThrough < size)
		{
			if (array[goThrough] < array[minIndex])
				minIndex = goThrough;
		        goThrough++;
		}
		if (minIndex != i)
		{
			swap = array[i];
			array[i] = array[minIndex];
			array[minIndex] = swap;
			print_array(array, size);
		}
		i++;
	}
}
