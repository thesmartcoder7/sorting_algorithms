#include "sort.h"

void hoare_sort(int *array, size_t size, int first, int last);
int hoare_partition(int *array, size_t size, int first, int last);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap - Swaps two integers in an array.
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
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @first: The starting index of the array partition to order.
 * @last: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int first, int last)
{
	int part;

	if (last - first > 0)
	{
		part = hoare_partition(array, size, first, last);
		hoare_sort(array, size, first, part - 1);
		hoare_sort(array, size, part, last);
	}
}


/**
 * hoare_partition - this Orders a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @first: The starting index of the subset to order.
 * @last: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int first, int last)
{
	int pivot, upper, lower;

	pivot = array[last];
	for (upper = first - 1, lower = last + 1; upper < lower;)
	{
		do {
			upper++;
		} while (array[upper] < pivot);
		do {
			lower--;
		} while (array[lower] > pivot);

		if (upper < lower)
		{
			swap(array + upper, array + lower);
			print_array(array, size);
		}
	}

	return (upper);
}


/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: this Uses the Hoare partition scheme and Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
