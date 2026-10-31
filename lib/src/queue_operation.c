/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:22:32 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/31 21:54:03 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "queue_internal.h"
#include "utils.h"

t_bool	queue_enqueue(t_queue *queue, const void *data)
{
	size_t	index;

	if (!queue || !data)
		return (False);
	if (queue->size == queue->capacity)
	{
		queue->capacity = ds_grow(
			&queue->container, queue->capacity,
			queue->data_size, queue->size
		);
		if (queue->capacity == 0)
			return (False);
	}
	index = (queue->front + queue->size) % queue->capacity;
	ft_memcpy(
		queue->container + index * queue->data_size,
		data, queue->data_size
	);
	queue->size++;
	return (True);
}

t_bool	queue_dequeue(t_queue *queue, void *store)
{
	if (!queue || queue->size == 0)
		return (False);
	if (store)
		ft_memcpy(
			store,
			queue->container + queue->front * queue->data_size,
			queue->data_size
		);
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return (True);
}

t_bool	queue_peek(const t_queue *queue, void *store)
{
	if (!queue || queue->size == 0)
		return (False);
	if (store)
		ft_memcpy(
			store,
			queue->container + queue->front * queue->data_size,
			queue->data_size
		);
	return (True);
}
