/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:18:58 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/18 15:52:33 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	stack_init(t_stack *stack, size_t data_size)
{
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = data_size;
}

void	stack_destroy(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->container);
	stack->container = NULL;
	stack->size = 0;
	stack->capacity = 0;
	stack->data_size = 0;
}
