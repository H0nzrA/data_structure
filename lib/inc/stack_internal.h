/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:56:43 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:48:50 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_STACK_INTERNAL_H
# define H0NZRA_STACK_INTERNAL_H

# include "stack.h"

/**
 * @brief Stores the internal state and metadata of a stack.
 */
typedef struct e_stack
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
}					t_stack;

#endif // !H0NZRA_STACK_INTERNAL_H
