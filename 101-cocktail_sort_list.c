#include "sort.h"

/**
 * swap_ahead - funtion that swaps a node in a listint_t doubly-linked
 *		list of integers with the node ahead of it.
 * @list: A pointer to the head of the list of integers.
 * @tail: A pointer to the tail of the list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
*/

void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}

/**
 * swap_behind - funt that swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of the list of integers.
 * @tail: A pointer to the tail of the list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
*/

void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - function that sorts a listint_t doubly-linked
 *			list of integers in ascending order using the
 *			cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool is_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (is_not_stirred == false)
	{
		is_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				is_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				is_not_stirred = false;
			}
		}
	}
}
