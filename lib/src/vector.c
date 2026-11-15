/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:45:40 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 18:39:48 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_internal.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

t_vector	*vector_create(size_t data_size)
{
	t_vector	*vector;

	if (data_size == 0)
		return (NULL);
	vector = (t_vector *)malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->data_size = data_size;
	vector->size = 0;
	vector->capacity = 0;
	vector->container = NULL;
	return (vector);
}

void	vector_destroy(t_vector *vector)
{
	if (!vector)
		return ;
	if (vector->container)
		free(vector->container);
	vector->container = NULL;
	vector->size = 0;
	vector->capacity = 0;
	free(vector);
}

t_bool	vector_push(t_vector *vector, void *data)
{
	size_t	offset;

	if (!vector || !data)
		return (False);
	if (vector->size == vector->capacity)
		if (
			!ds_grow(
				&vector->container,
				&vector->capacity, vector->data_size
			)
		)
			return (False);
	offset = vector->size * vector->data_size;
	memcpy(vector->container + offset, data, vector->data_size);
	vector->size++;
	return (True);
}

t_bool	vector_pop(t_vector *vector, void *store)
{
	size_t	last;

	if (!vector || !vector->size)
		return (False);

	last = (vector->size - 1) * vector->data_size;
	if (store)
		memcpy(store, vector->container + last, vector->data_size);
	vector->size--;
	if (vector->size > 1 && vector->size <= vector->capacity / 4)
		ds_shrink(
			&vector->container, &vector->capacity,
			vector->data_size
		);
	return (True);
}
