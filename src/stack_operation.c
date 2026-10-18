/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:07:28 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/18 15:43:28 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include <stdint.h>

t_bool	stack_push(t_stack *stack, const void *data)
{
	size_t	offset;

	if (!stack || !data || !stack->data_size)
		return (False);
	if (stack->size > SIZE_MAX / stack->data_size)
		return (False);
	if (stack->size == stack->capacity)
	{
		stack->capacity = ds_grow(
			&stack->container, stack->capacity,
			stack->data_size, stack->size
		);
		if (!stack->capacity)
			return (False);
	}
	offset = stack->size * stack->data_size;
	ft_memcpy(stack->container + offset, data, stack->data_size);
	stack->size++;
	return (True);
}

t_bool	stack_pop(t_stack *stack, void *store)
{
	size_t	last;

	if (!stack || !stack->data_size || !stack->size)
		return (False);
	last = (stack->size - 1) * stack->data_size;
	if (store)
		ft_memcpy(store, stack->container + last, stack->data_size);
	stack->size--;
	if (stack->size > 1 && stack->size <= stack->capacity / 4)
		stack->capacity = ds_shrink(
			&stack->container, stack->capacity,
			stack->data_size, stack->size
		);
	return (True);
}

t_bool	stack_top(const t_stack *stack, void *store)
{
	size_t	last;

	if (!stack || !stack->data_size || !stack->size)
		return (False);
	last = (stack->size - 1) * stack->data_size;
	if (store)
		ft_memcpy(store, stack->container + last, stack->data_size);
	return (True);
}

t_bool	stack_is_empty(const t_stack *stack)
{
	return (!stack || stack->size == 0);
}

size_t	stack_size(const t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->size);
}
