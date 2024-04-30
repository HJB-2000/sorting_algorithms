#include "sort.h"
/**
 * shell_sort - Perform Shell sort on an array of integers in
 * ascending order, utilizing the Knuth sequence.
 *
 * @size: size of the array
 * @array: array of numbers
 */

void shell_sort(int *array, size_t size)
{
	size_t i;
	size_t a = 1, b = 0;

	if (array == NULL || size < 2)
		return;
	while (a < size / 3)
		a = 3 * a + 1;
	while (a >= 1)
	{
		for (i = a; i < size; i++)
			for (b = i; b >= a &&
					(array[b] < array[b - a]); b -= a)
				swap(array, b, b - a);
		print_array(array, size);
		a /= 3;
	}
}
/**
 * swap - Swaps the positions of two elements in an array.
 *
 * @array: The array.
 * @n1: Index of the first element to swap.
 * @n2: Index of the second element to swap.
 */
void swap(int *array, ssize_t n1, ssize_t n2)
{
	int a;

	a = array[n1];
	array[n1] = array[n2];
	array[n2] = a;
}
