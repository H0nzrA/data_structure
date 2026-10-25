#ifndef HEAPQ_H
# define HEAPQ_H

# include <stdlib.h>

typedef enum e_heapq_type
{
	min_heapq,
	max_heapq
}						t_heapq_type;

typedef int				(*t_compare)(const void *a, const void *b);

typedef struct s_heapq	t_heapq;

t_heapq					*heapq_create(
	size_t data_size,
	t_compare compare,
	t_heapq_type type
);
void					heapq_destroy(t_heapq *heapq);

int						heapq_push(t_heapq *heapq, void *data);
int						heapq_pop(t_heapq *heapq, void *store);
int						heapq_peek(t_heapq *heapq, void *store);

#endif // !HEAPQ_H
