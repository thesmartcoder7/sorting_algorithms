#include "sort.h"
/**
  * selection_sort - this sorts an array of integers in ascending order
  *                  using the selection sort algorithm.
  * @array: array argument to sort
  * @size: size of array
  * Description: Prints the array after each swap.
  */
void selection_sort(int *array, size_t size)
{
	size_t i, i2;
	int least, temp, idx;

	for (i = 0; i < size; i++)
	{
		least = array[i];
		for (i2 = i + 1; i2 < size; i2++)
		{
			if (least > array[i2])
			{
				least = array[i2];
				idx = i2;
			}
		}
		if (least != array[i])
		{
			temp = array[i];
			array[i] = least;
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
