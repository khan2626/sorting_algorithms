#include "sort.h"

/**
 * swap_n - swaps 2 nodes in a doubly linked list
 * @h: head pointer
 * @node1: pointer to first node
 * @node2: second node to swap
 * Return: Nothing
 */
void swap_n(listint_t **h, listint_t **node1, listint_t *node2)
{
  (*node1)->next = node2->next;
  if (node2->next != NULL)
    node2->next->prev = *node1;
  node2->prev = (*node1)->prev;
  node2->next = *node1;

  if ((*node1)->prev != NULL)
    (*node1)->prev->next = node2;
  else
    *h = node2;
  (*node1)->prev = node2;
  *node1 = node2->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: A pointer to head of the list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *i, *j, *tmp;

  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;
  for (i = (*list)->next; i != NULL; i = tmp)
    {
      tmp = i->next;
      j = i->prev;
      while (j != NULL && i->n < j->n)
	{
	  swap_n(list, &j, i);
	  print_list((const listint_t *)*list);
	}
    }
}
     
