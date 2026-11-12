/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 20:19:26 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <string.h>

size_t	ds_grow(
	unsigned char **container,
	size_t capacity, size_t data_size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;

	if (capacity == 0)
		new_capacity = 1;
	else
		new_capacity = capacity * 2;
	new_container = (unsigned char *) realloc(*container, data_size * new_capacity);
	if (!new_container)
		return (0);
	*container = new_container;
	return (new_capacity);
}

size_t	ds_shrink(
	unsigned char **container,
	size_t capacity, size_t data_size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;

	if (capacity <= 1)
		return (capacity);
	new_capacity = capacity / 4;
	new_container = (unsigned char *) realloc(*container, data_size * new_capacity);
	if (!new_container)
		return (0);
	*container = new_container;
	return (new_capacity);
}
