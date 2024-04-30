#include "sort.h"


/**
 * swap_node - Swap a node with its previous node in a linked list.
 *
 * @node: pointer to the node to be swapped
 * @list: pointer to the linked list
 * Return: pointer to the node that was swapped
 */

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev;
	listint_t *next_node = node;

	prev_node->next = next_node->next;
	if (next_node->next)
		next_node->next->prev = prev_node;
	next_node->next = prev_node;
	next_node->prev = prev_node->prev;
	prev_node->prev = next_node;
	if (next_node->prev)
		next_node->prev->next = next_node;
	else
		*list = next_node;
	return (next_node);
}

/**
 * cocktail_sort_list - Perform cocktail sort on a doubly linked list.
 *
 * @list: pointer to the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	node = *list;
	for (; swap == 1; swap = 0)
	{
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		for (; node->prev;)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
