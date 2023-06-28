
#include "sort.h"

void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_ahead - this Swaps a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_ptr: A pointer to the current swapping node of the cocktail shaker.
 */
void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker_ptr)
{
	listint_t *temp = (*shaker_ptr)->next;

	if ((*shaker_ptr)->prev != NULL)
		(*shaker_ptr)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker_ptr)->prev;
	(*shaker_ptr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker_ptr;
	else
		*tail = *shaker_ptr;
	(*shaker_ptr)->prev = temp;
	temp->next = *shaker_ptr;
	*shaker_ptr = temp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker_ptr: A pointer to the current swapping node of the cocktail shaker.
 */
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker_ptr)
{
	listint_t *temp = (*shaker_ptr)->prev;

	if ((*shaker_ptr)->next != NULL)
		(*shaker_ptr)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker_ptr)->next;
	(*shaker_ptr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker_ptr;
	else
		*list = *shaker_ptr;
	(*shaker_ptr)->next = temp;
	temp->prev = *shaker_ptr;
	*shaker_ptr = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool unstirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (unstirred == false)
	{
		unstirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				unstirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				unstirred = false;
			}
		}
	}
}
