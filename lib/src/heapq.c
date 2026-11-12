/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:16 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 22:22:07 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "heapq_internal.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

t_heapq	*heapq_create(size_t data_size, t_compare compare, t_heapq_type type)
{
	t_heapq	*heapq;

	if (!data_size || !compare)
		return (NULL);
	if (type != min_heap && type != max_heap)
		return (NULL);
	heapq = (t_heapq *) malloc(sizeof(t_heapq));
	if (!heapq)
		return (NULL);
	heapq->container = NULL;
	heapq->size = 0;
	heapq->capacity = 0;
	heapq->data_size = data_size;
	heapq->func_compare = compare;
	heapq->type = type;
	return (heapq);
}

void	heapq_destroy(t_heapq *heapq)
{
	if (!heapq)
		return ;
	if (heapq->container)
		free(heapq->container);
	heapq->size = 0;
	heapq->capacity = 0;
	heapq->data_size = 0;
	heapq->func_compare = NULL;
	free(heapq);
}

t_bool	heapq_push(t_heapq *heapq, const void *data)
{
	size_t	index;

	if (!heapq || !data)
		return (False);
	if (heapq->size == heapq->capacity)
	{
		heapq->capacity = ds_grow(
			&heapq->container, heapq->capacity,
			heapq->data_size
		);
		if (heapq->capacity == 0)
			return (False);
	}
	index = heapq->size;
	memcpy(
		heapq->container + index * heapq->data_size,
		data, heapq->data_size
	);
	heapq->size++;
	heapqu_sift_up(heapq, index);
	return (True);
}

t_bool	heapq_pop(t_heapq *heapq, void *store)
{
	unsigned char	*root;
	unsigned char	*last;

	if (!heapq)
		return (False);
	root = heapq->container;
	last = heapq->container + (heapq->size - 1) * heapq->data_size;
	if (heapq->size == 0)
		return (False);
	if (store)
		memcpy(store, root, heapq->data_size);
	if (heapq->size > 1)
		memcpy(root, last, heapq->data_size);
	heapq->size--;
	heapqu_sift_down(heapq, 0);
	if (heapq->size > 1 && heapq->size <= heapq->capacity / 4)
		heapq->capacity = ds_shrink(
			&heapq->container, heapq->capacity,
			heapq->data_size
		);
	return (True);
}

t_bool	heapq_peek(const t_heapq *heapq, void *store)
{
	unsigned char	*root;

	if (!heapq)
		return (False);
	root = heapq->container;
	if (heapq->size == 0)
		return (False);
	if (store)
		memcpy(store, root, heapq->data_size);
	return (True);
}

t_bool	heapq_set_type(t_heapq *heapq, t_heapq_type type)
{
	if (!heapq || heapq->size == 0 || heapq->data_size == 0)
		return (False);
	if (type != min_heap && type != max_heap)
		return (False);
	heapq->type = type;
	heapqu_heapify(heapq);
	return (True);
}

t_bool	heapq_set_compare(t_heapq *heapq, t_compare compare)
{
	if (!heapq || heapq->size == 0 || heapq->data_size == 0)
		return (False);
	if (!compare)
		return (False);
	heapq->func_compare = compare;
	heapqu_heapify(heapq);
	return (True);
}

size_t					heapq_size(const t_heapq *heapq)
{
	if (!heapq)
		return (-1);
	return (heapq->size);
}

t_bool					heapq_is_empty(const t_heapq *heapq)
{
	if (!heapq)
		return (False);
	return (heapq->size == 0);
}
