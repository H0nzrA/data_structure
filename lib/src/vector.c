/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:45:40 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 18:05:37 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "vector_internal.h"
#include "utils.h"
#include <stdlib.h>

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

t_bool	vector_push(t_vector *vector, void *data);
