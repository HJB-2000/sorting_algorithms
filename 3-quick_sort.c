#include "sort.h"
/**
 * swap - Swaps the positions of two elements in an array.
 *
 * @array: The array.
 * @item1: Index of the first element to swap.
 * @item2: Index of the second element to swap.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int a;

	a = array[item1];
	array[item1] = array[item2];
	array[item2] = a;
}
/**
 * lomuto - Implements the Lomuto partition sorting scheme.
 *
 * @array: The array to partition.
 * @f: The index of the first element.
 * @l: The index of the last element.
 * @len: The size of the array.
 *
 * Return: The position of the last element after sorting.
 */
int lomuto(int *array, ssize_t f, ssize_t l, size_t len)
{
	int p = array[l];
	ssize_t c = f, x;

	x = f;
	while (x < l)
	{
		if (array[x] < p)
		{
			if (array[c] != array[x])
			{
				swap(array, c, x);
				print_array(array, len);
			}
			c++;
		}
		x++;
	}
	if (array[c] != array[l])
	{
		swap(array, c, l);
		print_array(array, len);
	}
	return (c);
}
/**
 * quick_sort_0 - Implements the quicksort algorithm.
 *
 * @array: The array to sort.
 * @f: The starting index of the array.
 * @l: The ending index of the array.
 * @len: The size of the array.
 */
void quick_sort_0(int *array, ssize_t f, ssize_t l, int len)
{
	ssize_t position = 0;


	if (f < l)
	{
		position = lomuto(array, f, l, len);

		quick_sort_0(array, f, position - 1, len);
		quick_sort_0(array, position + 1, l, len);
	}
}
/**
 * quick_sort - Prepares the terrain for the quicksort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_0(array, 0, size - 1, size);
}
