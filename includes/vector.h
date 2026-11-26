#ifndef H0NZRA_VECTOR_H
# define H0NZRA_VECTOR_H

# include <stdlib.h>

typedef struct s_vector	t_vector;

t_vector				*vector_create(size_t data_size);
void					vector_destroy(t_vector *vector);

int						vector_push(t_vector *vector, void *data);
int						vector_pop(t_vector *vector, void *store);

size_t					vector_size(t_vector *vector);
size_t					vector_capacity(t_vector *vector);
int						vector_is_empty(t_vector *vector);
void					vector_clear(t_vector *vector);

int						vector_set(t_vector *vector, size_t index, void *data);
int						vector_get(t_vector *vector, size_t index, void *store);

int						vector_reserve(t_vector *vector, size_t reserve);

#endif // !H0NZRA_VECTOR_H
