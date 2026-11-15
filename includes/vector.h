#ifndef H0NZRA_VECTOR_H
# define H0NZRA_VECTOR_H

# include <stdlib.h>

typedef struct s_vector	t_vector;

t_vector				*vector_create(size_t data_size);
void					vector_destroy(t_vector *vector);

#endif // !H0NZRA_VECTOR_H
