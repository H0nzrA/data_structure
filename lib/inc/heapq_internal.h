/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:43:09 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 17:44:38 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_INTERNAL_H
# define HEAPQ_INTERNAL_H

# include "heapq.h"

typedef struct s_heapq
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	t_compare		func_compare;
	t_heapq_type	type;
}					t_heapq;

#endif // !HEAPQ_INTERNAL_H
