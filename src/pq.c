/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:16 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/06 00:20:44 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pq.h"
#include "pq_utility.h"
#include <stdlib.h>
#include <string.h>

t_bool	pq_init(t_pq *pq, size_t data_size, t_compare compare, t_pq_type type)
{
	pq->container = NULL;
	pq->size = 0;
	pq->capacity = 0;
	pq->data_size = data_size;
	pq->func_compare = compare;
	pq->type = type;
	return (true);
}

t_bool	pq_destroy(t_pq *pq)
{
	if (pq->container)
		free(pq->container);
	pq->size = 0;
	pq->capacity = 0;
	pq->data_size = 0;
	pq->func_compare = NULL;
	return (true);
}

t_bool	pq_push(t_pq *pq, void *data)
{
	size_t	index;

	if (pq->size == pq->capacity && !pqu_grow(pq))
		return (false);
	index = pq->size;
	memcpy(
		pq->container + index * pq->data_size,
		data,
		pq->data_size
	);
	pq->size++;
	pqu_shift_up(pq, index);
	return (true);
}

t_bool	pq_pop(t_pq *pq, void *store)
{
	unsigned char	*root;
	unsigned char	*last;

	root = pq->container;
	last = pq->container + (pq->size - 1) * pq->data_size;
	if (pq->size == 0)
		return (false);
	if (store)
		memcpy(store, root, pq->data_size);
	if (pq->size > 1)
		memcpy(root, last, pq->data_size);
	pq->size--;
	pqu_shift_down(pq, 0);
	if (pq->size > 1
		&& pq->size <= pq->capacity / 4
		&& !pqu_shrink(pq))
		return (false);
	return (true);
}

t_bool	pq_peek(t_pq *pq, void *store)
{
	unsigned char	*root;

	root = pq->container;
	if (pq->size == 0)
		return (false);
	if (store)
		memcpy(store, root, pq->data_size);
	return (true);
}
