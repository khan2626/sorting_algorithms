#include "sort.h"
/**
 * merge_array - it sorts integers in ascending order
 * @buff: a buffer to store the sorted array
 * Return: Nothing
 */
void merge_array(int *array, int *buff, size_t front, size_t mid, size_t back)
{
  size_t i, j, k = 0;

  printf("merging...\n[left]: ");
  print_array(array + front, mid - front);

  printf("[right]: ");
  print_array(array + mid, back - mid);

  for (i = front, j = mid; i < mid && j < back; k++)
    buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];
  for (; i < mid; i++)
    buff[k++] = array[i];
  for (; j < back; j++)
    buff[k++] = array[j];
  for (i = front, k = 0; i < back; i++)
    array[i] = buff[k++];

  printf("[Done]: ");
  print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - it splits array into sub-array
 * @array: the array of integers to split
 * @front: lower bound of the array
 * @back: upper bound of the array
 * Return: Nothing
 */
void merge_sort_recursive(int *array, int *buff, size_t front, size_t back)
{
  size_t mid;

  if (back - front > 1)
    {
      mid = front + (back - front) / 2;

      merge_sort_recursive(array, buff, front, mid);
      merge_sort_recursive(array, buff, mid, back);
      merge_array(array, buff, front, mid, back);
    }
}

/**
 * merge_sort - sorts integers in ascending order
 * @array: array of integers to sort
 * @size: size of the array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
  int *buff;

  if (array == NULL || size < 2)
    return;

  buff = malloc(sizeof(int) * size);
  if (buff == NULL)
    return;

  merge_sort_recursive(array, buff, 0, size);
  free(buff);
}
