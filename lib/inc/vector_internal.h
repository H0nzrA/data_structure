/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:43:30 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/15 17:47:45 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_VECTOR_INTERNAL_H
# define H0NZRA_VECTOR_INTERNAL_H

# include <stdlib.h>

typedef struct s_vector
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
}					t_vector;

#endif // !H0NZRA_VECTOR_INTERNAL_H
