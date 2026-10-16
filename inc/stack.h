/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:15:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:24:39 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "utils.h"
# include <stdlib.h>

typedef struct e_stack
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
}					t_stack;

t_bool				stack_init(t_stack *stack, size_t data_size);
t_bool				stack_destroy(t_stack *stack);

t_bool				stack_push(t_stack *stack, void *data);
t_bool				stack_pop(t_stack *stack, void *store);
t_bool				stack_peek(t_stack *stack, void *store);

#endif // !STACK_H
