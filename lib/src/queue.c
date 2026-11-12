/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:15:42 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 20:21:34 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "queue_internal.h"
#include <stdlib.h>
#include <string.h>

t_queue	*queue_create(size_t data_size)
{
	t_queue	*queue;

	if (!data_size)
		return (NULL);
	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->data_size = data_size;
	queue->container = NULL;
	queue->size = 0;
	queue->capacity = 0;
	queue->front = 0;
	return (queue);
}

void	queue_destroy(t_queue *queue)
{
	if (!queue)
		return ;
	if (queue->container)
		free(queue->container);
	queue->container = NULL;
	queue->data_size = 0;
	queue->size = 0;
	queue->capacity = 0;
	queue->front = 0;
	free(queue);
}

t_bool	queue_enqueue(t_queue *queue, const void *data)
{
	size_t	index;

	if (!queue || !data)
		return (False);
	if (queue->size == queue->capacity && !queue_grow(queue))
		return (False);
	index = (queue->front + queue->size) % queue->capacity;
	memcpy(
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
		memcpy(
			store,
			queue->container + queue->front * queue->data_size,
			queue->data_size
		);
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	if (queue->size <= queue->capacity / 4 && !queue_shrink(queue))
		return (False);
	return (True);
}

t_bool	queue_peek(const t_queue *queue, void *store)
{
	if (!queue || queue->size == 0)
		return (False);
	if (store)
		memcpy(
			store,
			queue->container + queue->front * queue->data_size,
			queue->data_size
		);
	return (True);
}
