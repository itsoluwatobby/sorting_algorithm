#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enum for Boolean values.
 * @false: 0.
 * @true: 1.
*/

typedef enum bool
{
	false = 0,
	true
} bool;

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

/* Printing helper functions provided to the program */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* FUNCTION TO SWAP VARIABLES */
void swap_ints(int *a, int *b);

/* FUNCTION THAT RETURNS THE MAX VALUE IN AN ARRAY */
int _max(int *array, int size);

/* Sorting algorithm functions */

/* BUBBLE SORT */
void bubble_sort(int *array, size_t size);

/* INSERTION SORT */
void insertion_sort_list(listint_t **list);
void swap_var(listint_t *node1, listint_t *node2, listint_t **head);

/* SELECTION SORT */
void selection_sort(int *array, size_t size);

/* QUICK SORT */
void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, int start, int end, size_t size);
int partition(int *array, int start, int end, size_t size);

/* SHELL SORT */
void shell_sort(int *array, size_t size);

/* COCKTAIL SORT LIST */
void cocktail_sort_list(listint_t **list);
void swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);

/* COUNTING SORT */
void counting_sort(int *array, size_t size);

/* MERGE SORT */
void merge_sort(int *array, size_t size);
void merge_arr(int *subarr, int *buffer, size_t start, size_t middle,
		size_t end);
void merge_recursive(int *subarr, int *buffer, size_t start, size_t end);

/* HEAP SORT */
void heap_sort(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t base, size_t root);

/* RADIX SORT */
void radix_sort(int *array, size_t size);
void radix_count_sort(int *array, size_t size, int sig, int *buffer);

/* BITONIC SORT */
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);

/* QUICK_SORT_HOARE */
void quick_sort_hoare(int *array, size_t size);
void hoare_sort(int *array, int start, int end, size_t size);
int hoare_partition(int *array, int start, int end, size_t size);

#endif /* SORT_H */
