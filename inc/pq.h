#ifndef PQ_H
# define PQ_H

# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef int (*	t_compare)(const void *a, const void *b);

typedef struct s_pq
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	t_compare		func_compare;
}					t_pq;

t_bool				pq_init(t_pq *pq, size_t data_size, t_compare compare);

#endif // !PQ_H
