#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using bubble sort.
 *
 * @array: Array to be sorted.
 * @size: Length of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	int temp = 0;

	if (size < 2)
		return;

	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
