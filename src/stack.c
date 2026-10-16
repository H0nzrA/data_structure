/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:18:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/16 20:26:21 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include <stdlib.h>

t_bool	stack_init(t_stack *stack, size_t data_size)
{
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = data_size;
	return (True);
}

t_bool	stack_destroy(t_stack *stack)
{
	if (!stack)
		free(stack->container);
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = 0;
	return (True);
}

t_bool				stack_push(t_stack *stack, void *data);
t_bool				stack_pop(t_stack *stack, void *store);
t_bool				stack_peek(t_stack *stack, void *store);
