/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/25 21:46:02 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <string.h>

t_bool	ds_grow(
	unsigned char **container,
	size_t *capacity, size_t data_size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;

	if (*capacity == 0)
		new_capacity = 1;
	else
		new_capacity = *capacity * 2;
	new_container = (unsigned char *) realloc(*container, data_size * new_capacity);
	if (!new_container)
		return (False);
	*container = new_container;
	*capacity = new_capacity;
	return (True);
}

t_bool	ds_shrink(
	unsigned char **container,
	size_t *capacity, size_t data_size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;

	if (*capacity == 0)
		return (False);
	if (*capacity == 1)
		return (True);
	new_capacity = *capacity / 4;
	new_container = (unsigned char *) realloc(*container, data_size * new_capacity);
	if (!new_container)
		return (False);
	*container = new_container;
	*capacity = new_capacity;
	return (True);
}

t_bool	ds_reserve(
	unsigned char **container,
	size_t *capacity, size_t data_size,
	size_t reserve
)
{
	size_t			new_capacity;
	unsigned char	*new_container;

	if (!container)
		return (False);
	if (reserve == 0)
		return (True);
	if (*capacity == 0)
		new_capacity = reserve;
	else
		new_capacity = *capacity + reserve;
	new_container = (unsigned char *) realloc(*container, data_size * new_capacity);
	if (!new_container)
		return (False);
	*container = new_container;
	*capacity = new_capacity;
	return (True);
}
