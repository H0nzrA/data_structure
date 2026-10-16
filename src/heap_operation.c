/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:47:44 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/09 23:08:00 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "heap_utility.h"
#include <stdlib.h>
#include <string.h>

static int	compare_value(t_heap *heap, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;

	va = heap->container + a * heap->data_size;
	vb = heap->container + b * heap->data_size;
	return (heap->func_compare(va, vb));
}

static int	comparaison(t_heap *heap, size_t a, size_t b)
{
	int	res;

	res = compare_value(heap, a, b);
	if (heap->type == min_heap_type)
		return (-res);
	if (heap->type == max_heap_type)
		return (res);
	return (0);
}

void	heapu_swap(t_heap *heap, size_t a, size_t b)
{
	unsigned char	*va;
	unsigned char	*vb;
	unsigned char	tmp;
	size_t			i;

	va = heap->container + a * heap->data_size;
	vb = heap->container + b * heap->data_size;
	i = 0;
	while (i < heap->data_size)
	{
		tmp = va[i];
		va[i] = vb[i];
		vb[i] = tmp;
		i++;
	}
}

void	heapu_shift_up(t_heap *heap, size_t index)
{
	size_t	parent;

	while (index != 0)
	{
		parent = heapu_parent_node(index);
		if (comparaison(heap, index, parent) <= 0)
			break ;
		heapu_swap(heap, index, parent);
		index = parent;
	}
}

void	heapu_shift_down(t_heap *heap, size_t index)
{
	size_t	child;
	size_t	right_child;

	while (heapu_left_node(index) < heap->size)
	{
		child = heapu_left_node(index);
		right_child = heapu_right_node(index);
		if (right_child < heap->size && comparaison(heap, child,
				right_child) < 0)
			child = right_child;
		if (comparaison(heap, index, child) >= 0)
			break ;
		heapu_swap(heap, index, child);
		index = child;
	}
}
