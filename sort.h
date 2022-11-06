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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *x, int *y);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);
void merge_sort(int *array, size_t size);
void merge_sort_recurssion(int *array, int low, int high);
void merge(int *array, int low, int middle, int high);
void insertion_sort_list(listint_t **list);
void sort_list(listint_t *current, listint_t *previous, listint_t **list);

#endif
