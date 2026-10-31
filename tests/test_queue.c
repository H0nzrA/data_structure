#include "queue.h"
#include <stdio.h>

int	main(void)
{
	t_queue	*queue;

	queue = queue_create(sizeof(int));
	if (!queue)
		return (2);
	printf("enqueue 10: %d\n", queue_enqueue(queue, &(int){10}));
	printf("enqueue 20: %d\n", queue_enqueue(queue, &(int){20}));
	printf("enqueue 30: %d\n", queue_enqueue(queue, &(int){30}));
	printf("size: %zu\n", queue_size(queue));

	int store;
	queue_dequeue(queue, &store);
	printf("1 - %d\n", store);

	queue_dequeue(queue, &store);
	printf("2 - %d\n", store);

	queue_dequeue(queue, &store);
	printf("3 - %d\n", store);
	queue_destroy(queue);
	return (0);
}
