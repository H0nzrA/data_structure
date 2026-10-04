/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 22:18:28 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pq.h"
#include "pq_utility.h"
#include <stdlib.h>
#include <string.h>

t_bool	pqu_grow(t_pq *pq)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (pq->capacity == 0)
		new_capacity = 1;
	else
		new_capacity = pq->capacity * 2;
	new_container = (unsigned char *)malloc(pq->data_size * new_capacity);
	if (!new_container)
		return (false);
	i = 0;
	while (i < pq->size)
	{
		memcpy(
			new_container + i * pq->data_size,
			pq->container + i * pq->data_size,
			pq->data_size
		);
		i++;
	}
	free(pq->container);
	pq->container = new_container;
	pq->capacity = new_capacity;
	return (true);
}

t_bool	pqu_shrink(t_pq *pq)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (pq->capacity <= 1)
		return (false);
	new_capacity = pq->capacity / 4;
	new_container = (unsigned char *)malloc(pq->data_size * new_capacity);
	if (!new_container)
		return (false);
	i = 0;
	while (i < pq->size)
	{
		memcpy(
			new_container + i * pq->data_size,
			pq->container + i * pq->data_size,
			pq->data_size
		);
		i++;
	}
	free(pq->container);
	pq->container = new_container;
	pq->capacity = new_capacity;
	return (true);
}
