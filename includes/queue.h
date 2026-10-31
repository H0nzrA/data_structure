#ifndef H0NZRA_QUEUE_H
# define H0NZRA_QUEUE_H

# include <stdlib.h>

typedef struct s_queue	t_queue;

t_queue					*queue_create(size_t data_size);
void					queue_destroy(t_queue *queue);

int						queue_enqueue(t_queue *queue, const void *value);
int						queue_dequeue(t_queue *queue, void *store);
int						queue_peek(const t_queue *queue, void *store);
int						queue_is_empty(const t_queue *queue);
size_t					queue_size(const t_queue *queue);

void					queue_clear(t_queue *queue);

#endif // !H0NZRA_QUEUE_H
