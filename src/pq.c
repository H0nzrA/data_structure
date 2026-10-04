/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:16 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 21:04:56 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pq.h"
#include "pq_utility.h"
#include <stdlib.h>
#include <string.h>

t_bool	pq_init(t_pq *pq, size_t data_size, t_compare compare)
{
	pq->container = NULL;
	pq->size = 0;
	pq->capacity = 0;
	pq->data_size = data_size;
	pq->func_compare = compare;
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

t_bool	pq_pop(t_pq *pq, void *store);
t_bool	pq_peek(t_pq *pq, void *store);
