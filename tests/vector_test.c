#include "../lib/inc/vector.h"
#include <stdio.h>

int	main(void)
{
	t_vector	*vector;
    int data[20] = {
        42, 17, 8, 93, 25,
        61, 3, 74, 36, 12,
        89, 50, 6, 28, 95,
        41, 19, 67, 31, 54
    };

	vector = vector_create(sizeof(int));
	if (!vector)
		return (1);
	for (int i = 0; i < 20; i++)
		if (!vector_push(vector, &data[i]))
		{
			vector_destroy(vector);
			return (2);
		}
	int store;
	for (int i = 0; i < 20; i++)
	{
		if (!vector_at(vector, i, &store))
		{
			vector_destroy(vector);
			return (3);
		}
		printf("Value %d: %d\n", i, store);
	}
	vector_destroy(vector);
	return (0);
}
