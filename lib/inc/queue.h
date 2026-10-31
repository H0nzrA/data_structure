/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:06:46 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/31 21:20:08 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_QUEUE_H
# define H0NZRA_QUEUE_H

# include "utils.h"
# include <stdlib.h>

typedef struct s_queue	t_queue;

t_queue					*queue_create(size_t data_size);
void					queue_destroy(t_queue *queue);

t_bool					queue_enqueue(t_queue *queue, const void *value);
t_bool					queue_dequeue(t_queue *queue, void *store);
t_bool					queue_peek(const t_queue *queue, void *store);

t_bool					queue_is_empty(const t_queue *queue);
size_t					queue_size(const t_queue *queue);

void					queue_clear(t_queue *queue);

#endif // !H0NZRA_QUEUE_H
