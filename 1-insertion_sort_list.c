#include "sort.h"

/**
 * swap_nodes - Swap a node with its previous one in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the left node before the swap
 * @b: Pointer to the right node before the swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sort a doubly linked list using insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;

		while (tmp->prev && tmp->prev->n > tmp->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}

		current = current->next;
	}
}
