#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
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
