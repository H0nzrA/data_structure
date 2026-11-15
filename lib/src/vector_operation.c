/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:51:56 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 19:29:39 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_internal.h"
#include "utils.h"
#include <stdint.h>
#include <string.h>

t_bool	vector_push(t_vector *vector, void *data)
{
	size_t	offset;

	if (!vector || !data)
		return (False);
	if (vector->size > SIZE_MAX / vector->data_size)
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

t_bool	vector_set(t_vector *vector, size_t index, void *data)
{
	size_t offset;

	if (!vector || !data || (index >= vector->size))
		return (False);
	offset = index * vector->data_size;
	memcpy(vector->container + offset, data, vector->data_size);
	return (True);
}

t_bool	vector_get(t_vector *vector, size_t index, void *store)
{
	size_t	offset;

	if (!vector || !store || (index >= vector->size))
		return (False);
	offset = index * vector->data_size;
	memcpy(store, vector->container + offset, vector->data_size);
	return (True);
}
