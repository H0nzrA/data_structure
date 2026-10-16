/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_relation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:05:31 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/04 21:05:58 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap_utility.h"

size_t	heapu_parent_node(size_t index)
{
	return ((index - 1) / 2);
}

size_t	heapu_left_node(size_t index)
{
	return (2 * index + 1);
}

size_t	heapu_right_node(size_t index)
{
	return (2 * index + 2);
}
