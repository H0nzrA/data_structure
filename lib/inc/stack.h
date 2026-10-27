/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:15:19 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:39:32 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_STACK_H
# define H0NZRA_STACK_H

# include "utils.h"
# include <stdlib.h>

/**
 * @brief Declares an opaque stack structure.
 */
typedef struct e_stack	t_stack;

/**
 * @brief Creates an empty stack for elements of a fixed size.
 * @param data_size Size in bytes of each element.
 * @return Pointer to the stack, or NULL on failure.
 */
t_stack					*stack_create(size_t data_size);

/**
 * @brief Releases the stack and its allocated resources.
 * @param stack Pointer to the stack to destroy.
 */
void					stack_destroy(t_stack *stack);

/**
 * @brief Pushes a copy of an element onto the stack.
 * @param stack Target stack;
 * @param data Pointer to the element to copy.
 * @return True on success, false otherwise.
 */
t_bool					stack_push(t_stack *stack, const void *data);

/**
 * @brief Removes the top element from the stack.
 * @param stack Target stack;
 * @param store Buffer for the removed element, or NULL to discard it.
 * @return True if an element was removed, false otherwise.
 */
t_bool					stack_pop(t_stack *stack, void *store);

/**
 * @brief Copies the top element without removing it.
 * @param stack Stack to inspect;
 * @param store Buffer to receive the element.
 * @return True if an element exists, false otherwise.
 */
t_bool					stack_top(const t_stack *stack, void *store);

/**
 * @brief Checks whether the stack is empty.
 * @param stack Stack to inspect.
 * @return True if empty, false otherwise.
 */
t_bool					stack_is_empty(const t_stack *stack);

/**
 * @brief Returns the number of elements in the stack.
 * @param stack Stack to inspect.
 * @return Number of elements in the stack.
 */
size_t					stack_size(const t_stack *stack);

#endif // !H0NZRA_STACK_H
