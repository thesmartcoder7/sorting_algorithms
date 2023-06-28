#include "sort.h"


/**
 * swap - this Swaps two integers in an array.
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
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t sm_ct = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, sm_ct, UP);
		bitonic_seq(array, size, start + sm_ct, sm_ct, DOWN);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_merge - this Sorts a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, move = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + move; i++)
		{
			if ((dir == UP && array[i] > array[i + move]) ||
			    (dir == DOWN && array[i] < array[i + move]))
				swap(array + i, array + i + move);
		}
		bitonic_merge(array, size, start, move, dir);
		bitonic_merge(array, size, start + move, move, dir);
	}
}


/**
 * bitonic_sort - this Sorts an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
