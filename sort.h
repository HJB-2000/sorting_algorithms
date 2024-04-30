#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/****************0-bubble_sort.c**********************/
void bubble_sort(int *array, size_t size);
/*****************1-insertion_sort_list.c************/
void insertion_sort_list(listint_t **list);
/**************2-selection_sort***********************/
void selection_sort(int *array, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
/**************3-quick_sort.c*************************/
void quick_sort(int *array, size_t size);
void swap(int *array, ssize_t item1, ssize_t item2);
int lomuto(int *array, ssize_t f, ssize_t l, size_t len);
void quick_sort_0(int *array, ssize_t f, ssize_t l, int len);
/****************100-shell_sort.c**********************/
void shell_sort(int *array, size_t size);
/****************101-cocktail_sort_list.c************/
void cocktail_sort_list(listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
#endif
