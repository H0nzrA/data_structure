/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:22:32 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 20:21:49 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "queue_internal.h"
#include "utils.h"
#include <string.h>

t_bool	queue_is_empty(const t_queue *queue)
{
	if (!queue)
		return (False);
	return (queue->size == 0);
}

size_t	queue_size(const t_queue *queue)
{
	return (queue->size);
}

void	queue_clear(t_queue *queue)
{
	if (!queue)
		return ;
	free(queue->container);
	queue->container = NULL;
	queue->size = 0;
	queue->capacity = 0;
	queue->front = 0;
}

t_bool	queue_resize(t_queue *queue, size_t new_capacity)
{
	unsigned char	*new_container;
	size_t			i;
	size_t			index;

	if (!queue || new_capacity < queue->size || new_capacity == 0)
		return (False);

	new_container = (unsigned char *)malloc(queue->data_size * new_capacity);
	if (!new_capacity)
		return (False);
	i = -1;
	while (++i < queue->size)
	{
		index = (queue->front + i) % queue->capacity;
		memcpy(
			new_container + i * queue->data_size,
			queue->container + index * queue->data_size,
			queue->data_size
		);
	}
	free(queue->container);
	queue->container = new_container;
	queue->capacity = new_capacity;
	queue->front = 0;
	return (True);
}

t_bool	queue_grow(t_queue *queue)
{
	size_t	capacity;

	if (!queue)
		return (False);
	if (queue->capacity == 0)
		capacity = 1;
	else
		capacity = queue->capacity * 2;
	if (!queue_resize(queue, capacity))
		return (False);
	return (True);
}

t_bool	queue_shrink(t_queue *queue)
{
	size_t	capacity;

	if (!queue)
		return (False);
	if (queue->capacity <= 2)
		return (True);
	capacity = queue->capacity / 2;
	if (!queue_resize(queue, capacity))
		return (False);
	return (True);
}
