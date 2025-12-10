#include "sort.h"

/**
 * swap_nodes - Swap a node with its previous one in a doubly linked list
 * @list: Pointer to the head of the list
 * @node: The node to move backward
 *
 * Return: 1 if a swap occurred, 0 otherwise
 */
int swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev;

	if (!node || !node->prev)
		return (0);

	prev = node->prev;
	prev->next = node->next;

	if (node->next)
		node->next->prev = prev;

	node->prev = prev->prev;
	node->next = prev;

	if (prev->prev)
		prev->prev->next = node;

	prev->prev = node;

	if (!node->prev)
		*list = node;

	return (1);
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

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			if (swap_nodes(list, temp))
				print_list(*list);
		}

		current = current->next;
	}
}
