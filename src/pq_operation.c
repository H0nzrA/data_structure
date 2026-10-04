/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:47:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 21:05:24 by trakotoz         ###   ########.fr       */
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
		if (compare_value(pq, index, parent) <= 0)
			break ;
		pqu_swap(pq, index, parent);
		index = parent;
	}
}

void	pqu_shift_down(t_pq *pq, size_t index);
