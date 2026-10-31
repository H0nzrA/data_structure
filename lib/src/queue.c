/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:15:42 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/31 21:56:15 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "queue_internal.h"
#include <stdlib.h>

t_queue	*queue_create(size_t data_size)
{
	t_queue	*queue;

	if (!data_size)
		return (NULL);
	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->data_size = data_size;
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
