/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_utility.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:14 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/17 12:30:56 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_UTILITY_H
# define HEAPQ_UTILITY_H

# include "heapq.h"
# include <stdlib.h>

void	heapqu_shift_up(t_heapq *heapq, size_t index);
void	heapqu_shift_down(t_heapq *heapq, size_t index);
void	heapqu_swap(t_heapq *heapq, size_t a, size_t b);

size_t	heapqu_parent_node(size_t index);
size_t	heapqu_right_node(size_t index);
size_t	heapqu_left_node(size_t index);

#endif // !HEAPQ_UTILITY_H
