#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 0

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

/* print_array.c */
void print_array(const int *array, size_t size);

/* print_list.c */
void print_list(const listint_t *list);

/* 0-bubble_sort.c */
void bubble_sort(int *array, size_t size);

/* 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);

/* 2-selection_sort.c */
void selection_sort(int *array, size_t size);

/* 3-quick_sort.c */
void quick_sort(int *array, size_t size);

/* 100-shell_sort.c */
void shell_sort(int *array, size_t size);

/* 101-cocktail_sort_list.c */
void cocktail_sort_list(listint_t **list);

/* 102-counting_sort */
void counting_sort(int *array, size_t size);

/* 103-merge_sort */
void merge_sort(int *array, size_t size);

/* 104-heap_sort */
void heap_sort(int *array, size_t size);

/* 105-radix_sort.c */
void radix_sort(int *array, size_t size);

/* 106-bitonic_sort.c */
void bitonic_sort(int *array, size_t size);

/* 107-quick_sort_hoare */
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
