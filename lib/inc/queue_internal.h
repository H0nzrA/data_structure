/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:59:06 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/01 12:16:12 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_QUEUE_INTERNAL_H
# define H0NZRA_QUEUE_INTERNAL_H

# include <stdlib.h>
# include "utils.h"

/**
 * @brief Stores the elements and metadata of a generic circular queue.
 */
typedef struct s_queue
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	size_t			front;
}					t_queue;

/**
 * @brief Resize the queue's allocated storage.
 * @param queue Queue to resize.
 * @param new_capacity New storage capacity.
 * @return True on success, False on failure.
 */
t_bool	queue_resize(t_queue *queue, size_t new_capacity);

/**
 * @brief Increases the queue's storage capacity.
 * @param queue Queue to grow.
 * @return True on success, False on failure.
 */
t_bool	queue_grow(t_queue *queue);

/**
 * @brief Decrease the queue's storage capacity.
 * @param queue Queue to shrink.
 * @return True on success, False on failure.
 */
t_bool	queue_shrink(t_queue *queue);

#endif // !H0NZRA_QUEUE_INTERNAL_H
