/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:12:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:30:50 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

typedef enum e_bool
{
	False,
	True
}		t_bool;

void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif // !UTILS_H
