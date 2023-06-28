#include "sort.h"

void merge_sort_recursive(int *arr_sub, int *arr_s, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_sub - Sort a subarray of integers.
 * @arr_sub: A subarray of an array of integers to sort.
 * @arr_s: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_sub(int *arr_sub, int *arr_s, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr_sub + front, mid - front);

	printf("[right]: ");
	print_array(arr_sub + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		arr_s[k] = (arr_sub[i] < arr_sub[j]) ? arr_sub[i++] : arr_sub[j++];
	for (; i < mid; i++)
		arr_s[k++] = arr_sub[i];
	for (; j < back; j++)
		arr_s[k++] = arr_sub[j];
	for (i = front, k = 0; i < back; i++)
		arr_sub[i] = arr_s[k++];

	printf("[Done]: ");
	print_array(arr_sub + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @arr_sub: A subarray of an array of integers to sort.
 * @arr_s: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *arr_sub, int *arr_s, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(arr_sub, arr_s, front, mid);
		merge_sort_recursive(arr_sub, arr_s, mid, back);
		merge_sub(arr_sub, arr_s, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *semi;

	if (array == NULL || size < 2)
		return;

	semi = malloc(sizeof(int) * size);
	if (semi == NULL)
		return;

	merge_sort_recursive(array, semi, 0, size);

	free(semi);
}
