#include "sort.h"

/**
 * selection_sort - it sorts integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
  long unsigned int temp, i, j;
  long unsigned int min;

  if (size < 2 || array == NULL)
    return;
  for (i = 0; i < size - 1; i++)
    {
      min = i;
      for (j = i + 1; j < size; j++)
	{
	  if (array[j] < array[min])
	    min = j;
	}
      if (min != i)
	{
	  temp = array[min];
	  array[min] = array[i];
	  array[i] = temp;
	  print_array(array, size);
	}
    }
}
