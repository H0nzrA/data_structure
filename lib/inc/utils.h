/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:12:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:55:36 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

/**
 * @brief Represents a boolean value.
 */
typedef enum e_bool
{
	False,
	True
}		t_bool;

/**
 * @brief Copies a specified number of bytes between memory regions.
 * @param dest Destination memory address.
 * @param src Source memory address.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Grows a container's allocated capacity when needed.
 * @param container Address of the container pointer to resize.
 * @param capacity Current capacity in elements.
 * @param data_size Size in bytes of each element.
 * @param size Number of elements currently stored.
 * @return Updated capacity, or 0 on failure.
 */
size_t	ds_grow(
			unsigned char **container,
			size_t capacity,
			size_t data_size,
			size_t size
		);

/**
 * @brief Shrinks a container's allocated capacity when appropriate.
 * @param container Address of the container pointer to resize.
 * @param capacity Current capacity in elements.
 * @param data_size Size in bytes of each element.
 * @param size Number of elements currently stored.
 * @return Updated capacity, or 0 on failure.
 */
size_t	ds_shrink(
			unsigned char **container,
			size_t capacity,
			size_t data_size,
			size_t size
		);

#endif // !UTILS_H
