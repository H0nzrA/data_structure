/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utility.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:14 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 16:01:43 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_UTILITY_H
# define HEAP_UTILITY_H

# include "heap.h"
# include <stdlib.h>

t_bool	heapu_grow(t_heap *heap);
t_bool	heapu_shrink(t_heap *heap);

void	heapu_shift_up(t_heap *heap, size_t index);
void	heapu_shift_down(t_heap *heap, size_t index);
void	heapu_swap(t_heap *heap, size_t a, size_t b);

size_t	heapu_parent_node(size_t index);
size_t	heapu_right_node(size_t index);
size_t	heapu_left_node(size_t index);

#endif // !HEAP_UTILITY_H
