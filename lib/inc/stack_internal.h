/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:56:43 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 17:56:52 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INTERNAL_H
# define STACK_INTERNAL_H

# include "stack.h"

typedef struct e_stack
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
}					t_stack;

#endif // !STACK_INTERNAL_H
