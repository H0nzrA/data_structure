#include "heap.h"
#include <stdio.h>

int	compare(const void *a, const void *b)
{
	return (*(const int *)a - *(const int *)b);
}

int	main(void)
{
	t_heap	heap;
	int		data;
	int		store;

	if (!heap_init(&heap, sizeof(int), compare, heap_min_type))
		return (1);
	data = 50;
	heap_push(&heap, &data);
	heap_pop(&heap, &store);
	printf("Store = %d\n", store);
	heap_destroy(&heap);
	return (0);
}
