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
		for (; n->prev && n->prev->n > n->n; n = nodeswap(n, list))
		{
			print_list(*list);
		}
	}
}
/**
 * nodeswap - Swaps a given node with its previous
 * node in a doubly linked list.
 *
 * @node: The node to swap.
 * @list: Pointer to the head of the list.
 *
 * Return: Pointer to the node that was swapped.
 */
listint_t *nodeswap(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
