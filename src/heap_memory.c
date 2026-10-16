/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:13:35 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "heap_utility.h"
#include <stdlib.h>
#include <string.h>

t_bool	heapu_grow(t_heap *heap)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (heap->capacity == 0)
		new_capacity = 1;
	else
		new_capacity = heap->capacity * 2;
	new_container = (unsigned char *)malloc(heap->data_size * new_capacity);
	if (!new_container)
		return (False);
	i = 0;
	while (i < heap->size)
	{
		ft_memcpy(new_container + i * heap->data_size, heap->container + i
			* heap->data_size, heap->data_size);
		i++;
	}
	free(heap->container);
	heap->container = new_container;
	heap->capacity = new_capacity;
	return (True);
}

t_bool	heapu_shrink(t_heap *heap)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (heap->capacity <= 1)
		return (False);
	new_capacity = heap->capacity / 4;
	new_container = (unsigned char *)malloc(heap->data_size * new_capacity);
	if (!new_container)
		return (False);
	i = 0;
	while (i < heap->size)
	{
		ft_memcpy(new_container + i * heap->data_size, heap->container + i
			* heap->data_size, heap->data_size);
		i++;
	}
	free(heap->container);
	heap->container = new_container;
	heap->capacity = new_capacity;
	return (True);
}
