#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n;

	if (list == NULL || (*list)->next == NULL)
		return;
	n = (*list)->next;
	for (; n; n = n->next)
	{
		for (; n->prev && n->prev->n > n->n; n = swap_node(n, list))
		{
			print_list(*list);
		}
	}
}
/**
 * swap_node - Swaps a given node with its previous
 * node in a doubly linked list.
 *
 * @node: The node to swap.
 * @list: Pointer to the head of the list.
 *
 * Return: Pointer to the node that was swapped.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current = node;

	if (prev_node)
	{
		prev_node->next = current->next;
		if (current->next)
			current->next->prev = prev_node;
		current->next = prev_node;
		current->prev = prev_node->prev;
		prev_node->prev = current;
		if (current->prev)
			current->prev->next = current;
		else
			*list = current;
	}
	return (current);
}
