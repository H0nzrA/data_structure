#include "vector.h"

int	main(void)
{
	t_vector	*vector;

	vector = vector_create(sizeof(int));
	if (!vector)
		return (1);
	vector_destroy(vector);
	return (0);
}
