/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:11 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:12:41 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include "utils.h"
# include <stdlib.h>

typedef enum e_heap_type
{
	min_heap_type,
	max_heap_type
}					t_heap_type;

typedef int			(*t_compare)(const void *a, const void *b);

typedef struct s_heap
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	t_compare		func_compare;
	t_heap_type		type;
}					t_heap;

/* Life of the data */
t_bool				heap_init(t_heap *heap, size_t data_size, t_compare compare,
						t_heap_type type);
t_bool				heap_destroy(t_heap *heap);

/* Priorit queue mandatory operations */
t_bool				heap_push(t_heap *heap, void *data);
t_bool				heap_pop(t_heap *heap, void *store);
t_bool				heap_peek(t_heap *heap, void *store);

#endif // !HEAP_H
