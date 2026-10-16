/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:16 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:13:13 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"
#include "heap_utility.h"
#include <stdlib.h>
#include <string.h>

t_bool	heap_init(t_heap *heap, size_t data_size, t_compare compare,
		t_heap_type type)
{
	heap->container = NULL;
	heap->size = 0;
	heap->capacity = 0;
	heap->data_size = data_size;
	heap->func_compare = compare;
	heap->type = type;
	return (True);
}

t_bool	heap_destroy(t_heap *heap)
{
	if (heap->container)
		free(heap->container);
	heap->size = 0;
	heap->capacity = 0;
	heap->data_size = 0;
	heap->func_compare = NULL;
	return (True);
}

t_bool	heap_push(t_heap *heap, void *data)
{
	size_t	index;

	if (heap->size == heap->capacity && !heapu_grow(heap))
		return (False);
	index = heap->size;
	memcpy(heap->container + index * heap->data_size, data, heap->data_size);
	heap->size++;
	heapu_shift_up(heap, index);
	return (True);
}

t_bool	heap_pop(t_heap *heap, void *store)
{
	unsigned char	*root;
	unsigned char	*last;

	root = heap->container;
	last = heap->container + (heap->size - 1) * heap->data_size;
	if (heap->size == 0)
		return (False);
	if (store)
		memcpy(store, root, heap->data_size);
	if (heap->size > 1)
		memcpy(root, last, heap->data_size);
	heap->size--;
	heapu_shift_down(heap, 0);
	if (heap->size > 1 && heap->size <= heap->capacity / 4
		&& !heapu_shrink(heap))
		return (False);
	return (True);
}

t_bool	heap_peek(t_heap *heap, void *store)
{
	unsigned char	*root;

	root = heap->container;
	if (heap->size == 0)
		return (False);
	if (store)
		memcpy(store, root, heap->data_size);
	return (True);
}
