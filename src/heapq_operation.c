/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:47:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/09 23:08:00 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heapq.h"
#include "heapq_utility.h"
#include <stdlib.h>
#include <string.h>

static int	compare_value(t_heapq *heapq, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;

	va = heapq->container + a * heapq->data_size;
	vb = heapq->container + b * heapq->data_size;
	return (heapq->func_compare(va, vb));
}

static int	comparaison(t_heapq *heapq, size_t a, size_t b)
{
	int	res;

	res = compare_value(heapq, a, b);
	if (heapq->type == min_heapq)
		return (-res);
	if (heapq->type == max_heapq)
		return (res);
	return (0);
}

void	heapqu_swap(t_heapq *heapq, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;
	unsigned char	tmp;
	size_t			i;

	va = heapq->container + a * heapq->data_size;
	vb = heapq->container + b * heapq->data_size;
	i = 0;
	while (i < heapq->data_size)
	{
		tmp = va[i];
		va[i] = vb[i];
		vb[i] = tmp;
		i++;
	}
}

void	heapqu_shift_up(t_heapq *heapq, size_t index)
{
	size_t	parent;

	while (index != 0)
	{
		parent = heapqu_parent_node(index);
		if (comparaison(heapq, index, parent) <= 0)
			break ;
		heapqu_swap(heapq, index, parent);
		index = parent;
	}
}

void	heapqu_shift_down(t_heapq *heapq, size_t index)
{
	size_t	child;
	size_t	right_child;

	while (heapqu_left_node(index) < heapq->size)
	{
		child = heapqu_left_node(index);
		right_child = heapqu_right_node(index);
		if (right_child < heapq->size && comparaison(heapq, child,
				right_child) < 0)
			child = right_child;
		if (comparaison(heapq, index, child) >= 0)
			break ;
		heapqu_swap(heapq, index, child);
		index = child;
	}
}
