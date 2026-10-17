/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_relation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:05:31 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 21:05:58 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heapq_utility.h"

size_t	heapqu_parent_node(size_t index)
{
	return ((index - 1) / 2);
}

size_t	heapqu_left_node(size_t index)
{
	return (2 * index + 1);
}

size_t	heapqu_right_node(size_t index)
{
	return (2 * index + 2);
}
