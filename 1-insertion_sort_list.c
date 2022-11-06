#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 * @list: pointer pointing to the head node
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *previous = *list;
	listint_t *tmp;
	int i = 0;

	if (*list == NULL)
		return;

	while (current != NULL)
	{
		current = current->next;
		i++;
	}

	if (i < 2)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current->next;
		if (current->n < previous->n)
		{
			sort_list(current, previous, list);
		}
		if (tmp == NULL)
		{
			break;
		}
		current = tmp;
		previous = current->prev;
	}
}

/**
 * sort_list - swap the node of doubly linked list
 * @current: pointer pointing to current node
 * @previous: pointer pointing to prevous node
 * @list: the pointer pointing to head node
 *
 * Return: Nothing
 */
void sort_list(listint_t *current, listint_t *previous, listint_t **list)
{
	listint_t *tmp_prev;
	listint_t *nxt;

	while (current != NULL && current->prev != NULL && current->n < previous->n)
	{
		nxt = current->next;
		if (previous->prev == NULL)
		{
			previous->next = nxt;
			previous->prev = current;
			current->next = previous;
			current->prev = NULL;
			nxt->prev = previous;
			*list = current;
		}
		else if (nxt == NULL)
		{
			tmp_prev = previous->prev;
			previous->next = nxt;
			previous->prev = current;
			current->next = previous;
			current->prev = tmp_prev;
			tmp_prev->next = current;
		}
		else
		{
			tmp_prev = previous->prev;
			previous->next = nxt;
			previous->prev = current;
			current->next = previous;
			current->prev = tmp_prev;
			nxt->prev = previous;
			tmp_prev->next = current;
		}

		previous = current->prev;
		print_list(*list);
	}

}
