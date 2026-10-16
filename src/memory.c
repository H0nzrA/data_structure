/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 21:05:38 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ds_grow(
	unsigned char **container,
	size_t capacity,
	size_t data_size,
	size_t size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (capacity == 0)
		new_capacity = 1;
	else
		new_capacity = capacity * 2;
	new_container = (unsigned char *)malloc(data_size * new_capacity);
	if (!new_container)
		return (0);
	i = -1;
	while (++i < size)
		ft_memcpy(
			new_container + i * data_size,
			container + i * data_size,
			data_size
		);
	free(*container);
	*container = new_container;
	return (new_capacity);
}

size_t	ds_shrink(
	unsigned char **container,
	size_t capacity,
	size_t data_size,
	size_t size
)
{
	size_t			new_capacity;
	unsigned char	*new_container;
	size_t			i;

	if (capacity <= 1)
		return (0);
	new_capacity = capacity / 4;
	new_container = (unsigned char *)malloc(data_size * new_capacity);
	if (!new_container)
		return (0);
	i = -1;
	while (++i < size)
		ft_memcpy(
			new_container + i * data_size,
			container + i * data_size,
			data_size
		);
	free(*container);
	*container = new_container;
	return (new_capacity);
}
