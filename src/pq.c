#include "pq.h"
#include <stdlib.h>

t_bool	pq_init(t_pq *pq, size_t data_size, t_compare compare)
{
	pq->container = NULL;
	pq->size = 0;
	pq->capacity = 0;
	pq->data_size = data_size;
	pq->func_compare = compare;
	return (true);
}
