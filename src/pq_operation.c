/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:47:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/06 00:22:53 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pq.h"
#include "pq_utility.h"
#include <string.h>
#include <stdlib.h>

static int	compare_value(t_pq *pq, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;

	va = pq->container + a * pq->data_size;
	vb = pq->container + b * pq->data_size;
	return (pq->func_compare(va, vb));
}

static int	comparaison(t_pq *pq, size_t a, size_t b)
{
	int	res;

	res = compare_value(pq, a, b);
	if (pq->type == pqt_minheap)
		return (res);
	return (-res);
}

void	pqu_swap(t_pq *pq, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;
	unsigned char	tmp;
	size_t			i;

	va = pq->container + a * pq->data_size;
	vb = pq->container + b * pq->data_size;
	i = 0;
	while (i < pq->data_size)
	{
		tmp = va[i];
		va[i] = vb[i];
		vb[i] = tmp;
		i++;
	}
}

void	pqu_shift_up(t_pq *pq, size_t index)
{
	size_t	parent;

	while (index != 0)
	{
		parent = pqu_parent_node(index);
		if (comparaison(pq, index, parent) <= 0)
			break ;
		pqu_swap(pq, index, parent);
		index = parent;
	}
}

void	pqu_shift_down(t_pq *pq, size_t index)
{
	size_t	child;
	size_t	right_child;

	while (pqu_left_node(index) < pq->size)
	{
		child = pqu_left_node(index);
		right_child = pqu_right_node(index);
		if (right_child < pq->size && comparaison(pq, child, right_child) < 0)
			child = right_child;
		if (comparaison(pq, index, child) >= 0)
			break ;
		pqu_swap(pq, index, child);
		index = child;
	}
}
