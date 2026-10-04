/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pq_utility.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:14 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 15:36:17 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PQ_UTILITY_H
# define PQ_UTILITY_H

# include "pq.h"
# include <stdlib.h>

t_bool		pqu_grow(t_pq *pq);
t_bool		pqu_shrink(t_pq *pq);

t_bool		pqu_shift_up(t_pq *pq, size_t index);
t_bool		pqu_shift_down(t_pq *pq, size_t index);
t_bool		pqu_swap(t_pq *pq, size_t a, size_t b);

size_t		pqu_parent_node(size_t index);
size_t		pqu_right_node(size_t index);
size_t		pqu_left_node(size_t index);

#endif // !PQ_UTILITY_H
