/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:59:06 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/31 21:42:13 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_QUEUE_INTERNAL_H
# define H0NZRA_QUEUE_INTERNAL_H

# include <stdlib.h>

typedef struct s_queue
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	size_t			front;
}					t_queue;

#endif // !H0NZRA_QUEUE_INTERNAL_H
