/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:15:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 18:06:41 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "utils.h"
# include <stdlib.h>

typedef struct e_stack	t_stack;

t_stack					*stack_create(size_t data_size);
void					stack_destroy(t_stack *stack);

t_bool					stack_push(t_stack *stack, const void *data);
t_bool					stack_pop(t_stack *stack, void *store);
t_bool					stack_top(const t_stack *stack, void *store);
t_bool					stack_is_empty(const t_stack *stack);
size_t					stack_size(const t_stack *stack);

#endif // !STACK_H
