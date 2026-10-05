/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:11 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/06 00:25:08 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQ_H
# define PQ_H

# include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef enum e_pq_type
{
	pqt_minheap,
	pqt_maxheap
}					t_pq_type;

typedef int (*	t_compare)(const void *a, const void *b);

typedef struct s_pq
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	t_compare		func_compare;
	t_pq_type		type;
}					t_pq;

/* Life of the data */
t_bool				pq_init(
						t_pq *pq,
						size_t data_size,
						t_compare compare,
						t_pq_type type
					);
t_bool				pq_destroy(t_pq *pq);

/* Priorit queue mandatory operations */
t_bool				pq_push(t_pq *pq, void *data);
t_bool				pq_pop(t_pq *pq, void *store);
t_bool				pq_peek(t_pq *pq, void *store);

#endif // !PQ_H
