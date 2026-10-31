/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:22:32 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/31 22:42:40 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "queue_internal.h"
#include "utils.h"

t_bool	queue_is_empty(const t_queue *queue)
{
	if (!queue)
		return (True);
	return ((t_bool)queue->size);
}

size_t	queue_size(const t_queue *queue)
{
	return (queue->size);
}

void	queue_clear(t_queue *queue)
{
	if (queue->container)
		free(queue->container);
	queue->size = 0;
	queue->capacity = 0;
	queue->front = 0;
}
