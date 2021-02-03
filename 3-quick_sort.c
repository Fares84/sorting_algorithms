#include "sort.h"

/**
 *partitioning_elements - takes last element as pivot and according to this
 *organizes to the left those less than the pivot and to the right those
 *greater tha the pivot
 *@array: the array to sort
 *@beg: those lower than the selected pivot
 *@end: those greater than the selected pivot
 *@size: array size
 *Return: index of swapped element
 */
int partitioning_elements(int *array, int beg, int end, size_t size)
{
	int idx, loc, swap, pivot = array[end];

	idx = beg - 1;

	for (loc = beg; loc < end; loc++)
	{
		if (array[loc] <= pivot)
		{
			idx++;
			swap = array[idx];
			array[idx] = array[loc];
			array[loc] = swap;
			if (idx != loc)
			print_array(array, size);
		}
	}
	swap = array[idx + 1];
	array[idx + 1] = array[end];
	array[end] = swap;
	if (end != (idx + 1))
		print_array(array, size);
	return (idx + 1);
}

/**
 *lomuto - implements the lomuto partition scheme
 *@array: array to be sorted
 *@beg: beginning of the array (start)
 *@end: the end of the array
 *@size: array size
 *return: void
 */
void lomuto(int *array, int beg, int end, size_t size)
{
	int loc;

	if (beg < end)
	{
		loc = partitioning_elements(array, beg, end, size);
		lomuto(array, beg, loc - 1, size);
		lomuto(array, loc + 1, end, size);
	}
}

/**
 *quick_sort - sorts an array in ascending order
 *implementation the lomoto partition scheme and setting
 *as pivot alaways the last element of the partition once is ordered
 *@array: array to be sorted
 *@size: array size
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		lomuto(array, 0, size - 1, size);
}
