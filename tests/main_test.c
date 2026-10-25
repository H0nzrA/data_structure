#include "heapq.h"
#include <stdio.h>

int	compare(const void *a, const void *b)
{
	return (*(const int *)a - *(const int *)b);
}

int	main(void)
{
	t_heapq	*heapq;

	heapq = heapq_create(sizeof(int), compare, min_heapq);
	if (!heapq)
		return (1);
	int data = 23;
	heapq_push(heapq, &data);

	data = 0;
	heapq_pop(heapq, &data);
	printf("%d\n", data);
	heapq_destroy(heapq);
	return (0);
}
