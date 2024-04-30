#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, a;
	int t, s, f = 0;

	if (array == NULL)
		return;
	i = 0;
	while (i < size)
	{
		t = i;
		f = 0;
		a = i + 1;
		while (a < size)
		{
			if (array[t] > array[a])
			{
				t = a;
				f += 1;
			}
			a++;
		}
		s = array[i];
		array[i] = array[t];
		array[t] = s;
		if (f != 0)
			print_array(array, size);
		i++;
	}

}
