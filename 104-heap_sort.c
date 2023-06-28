#include "sort.h"

void heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Turns a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @b_row: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *array, size_t size, size_t b_row, size_t root)
{
	size_t l, r, big;

	l = 2 * root + 1;
	r = 2 * root + 2;
	big = root;

	if (l < b_row && array[l] > array[big])
		big = l;
	if (r < b_row && array[r] > array[big])
		big = r;

	if (big != root)
	{
		swap(array + root, array + big);
		print_array(array, size);
		heapify(array, size, b_row, big);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
