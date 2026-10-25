/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:11 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 18:03:30 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_H
# define HEAPQ_H

# include "utils.h"
# include <stdlib.h>

typedef enum e_heapq_type
{
	min_heapq,
	max_heapq
}						t_heapq_type;

typedef int				(*t_compare)(const void *a, const void *b);

typedef struct s_heapq	t_heapq;

t_heapq					*heapq_create(
	size_t data_size,
	t_compare compare,
	t_heapq_type type
);
t_bool					heapq_destroy(t_heapq *heapq);

t_bool					heapq_push(t_heapq *heapq, void *data);
t_bool					heapq_pop(t_heapq *heapq, void *store);
t_bool					heapq_peek(t_heapq *heapq, void *store);

#endif // !HEAPQ_H
