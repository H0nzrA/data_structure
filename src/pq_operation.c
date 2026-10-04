/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:47:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 16:10:49 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pq.h"
#include "pq_utility.h"
#include <string.h>
#include <stdlib.h>

static void	*get_value(t_pq *pq, size_t index)
{
	void *store;

	store = (void *) malloc(pq->data_size);
	if (!store)
		return (NULL);
	memcpy(store, pq->container + index * pq->data_size, pq->data_size);
	return (store);
}

t_bool	pqu_swap(t_pq *pq, size_t a, size_t b)
{
	void *va;
	void *vb;
	void *tmp;

	tmp = malloc(pq->data_size);
	if (!tmp)
		return (false);
	va = (char *)pq->container + a * pq->data_size;
	vb = (char *)pq->container + b * pq->data_size;
	memcpy(tmp, va, pq->data_size);
	memcpy(va, vb, pq->data_size);
	memcpy(vb, tmp, pq->data_size);
	free(tmp);
	return (true);
}

t_bool	pqu_shift_up(t_pq *pq, size_t index)
{
	size_t	parent;
	void *va;
	void *vb;

	va = NULL;
	vb = NULL;
	while (index != 0)
	{
		parent = pqu_parent_node(index);
		va = get_value(pq, index);
		vb = get_value(pq, parent);
		if (!va || !vb)
		{
			free(va);
			free(vb);
			return (false);
		}
		if (pq->func_compare(va, vb) <= 0)
			break ;
		pqu_swap(pq, index, parent);
		free(va);
		free(vb);
		index = parent;
	}
	return (true);
}

t_bool	pqu_shift_down(t_pq *pq, size_t index)
{
	size_t	parent;
	void *va;
	void *vb;

	va = NULL;
	vb = NULL;
	while (index != 0)
	{
		parent = pqu_parent_node(index);
		va = get_value(pq, index);
		vb = get_value(pq, parent);
		if (!va || !vb)
		{
			free(va);
			free(vb);
			return (false);
		}
		if (pq->func_compare(va, vb) <= 0)
			break ;
		pqu_swap(pq, index, parent);
		free(va);
		free(vb);
		index = parent;
	}
	return (true);
}
