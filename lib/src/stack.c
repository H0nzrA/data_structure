/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:18:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 18:08:18 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "stack_internal.h"
#include <stdlib.h>

t_stack	*stack_create(size_t data_size)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = data_size;
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->container)
		free(stack->container);
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = 0;
	free(stack);
}
