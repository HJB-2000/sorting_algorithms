#include "sort.h"
#include <stdio.h>
/**
 * zeroalloc - Allocate memory for an array and set its contents to zero.
 *
 * @num_elements: number of elements in the array
 * @element_size: size of each element in bytes
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */
void *zeroalloc(unsigned int num_elements, unsigned int element_size)
{
	unsigned int i = 0;
	char *ptr;

	if (num_elements == 0 || element_size == 0)
		return (NULL);

	ptr = malloc(num_elements * element_size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (num_elements * element_size); i++)
		ptr[i] = '\0';

	return (ptr);
}


/**
 * merge_arrays - Merge two subarrays into a single array.
 *
 * @arr: pointer to the original array
 * @tmp: temporary array for merging
 * @start: starting index of the subarray
 * @mid: middle index of the subarray
 * @end: ending index of the subarray
 */
void merge_arrays(int *arr, int *tmp, int start, int mid, int end)
{
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	int left, right, i = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	left = 0;
	while (left < size_left)
	{
		array_left[left] = arr[start + left];
		left++;
	}
	right = 0;
	while (right < size_right)
	{
		array_right[right] = arr[mid + 1 + right];
		right++;
	}
	left = 0, right = 0, i = start;
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}
	while (left < size_left)
		arr[i] = array_left[left], left++, i++;
	while (right < size_right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}


/**
 * recursiveMergeSort - Recursive function to perform merge sort on an array.
 *
 * @arr: pointer to the array to be sorted
 * @tmp: temporary array for merging
 * @start: starting index of the subarray
 * @end: ending index of the subarray
 */
void recursiveMergeSort(int *arr, int *tmp, int start, int end)
{
	int middle;

	middle = (start + end) / 2;
	if ((start + end) % 2 == 0)
		middle--;

	if (middle >= start)
	{
		recursiveMergeSort(arr, tmp, start, middle);
		recursiveMergeSort(arr, tmp, middle + 1, end);
		merge_arrays(arr, tmp, start, middle, end);
	}
}
/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the merge sort algorithm.
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *i;

	if (!array || size < 2)
		return;
	i = zeroalloc(size, sizeof(int));
	recursiveMergeSort(array, i, 0, size - 1);
	free(i);
}
