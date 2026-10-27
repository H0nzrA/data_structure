/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:11 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:11:31 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_HEAPQ_H
# define H0NZRA_HEAPQ_H

# include "utils.h"
# include <stdlib.h>

/**
 * @brief Defines the ordering behavior of a heap-based priority queue.
 */
typedef enum e_heapq_type
{
	min_heapq,
	max_heapq
}						t_heapq_type;

/**
 * @brief Defines a function that compares two elements.
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return Negative for lower priority, zero for equal priority,
 *         positive for higher priority.
 */
typedef int				(*t_compare)(const void *a, const void *b);

/**
 * @brief Declares the opaque priority queue structure.
 */
typedef struct s_heapq	t_heapq;

/**
 * @brief Creates an empty priority queue.
 * @param data_size Size in bytes of each element.
 * @param compare Function used to compare elements.
 * @param type Ordering mode: min-heap or max-heap.
 * @return Pointer to the queue, or NULL on failure.
 */
t_heapq					*heapq_create(
	size_t data_size,
	t_compare compare,
	t_heapq_type type
);
/**
 * @brief Releases the priority queue and its allocated resources.
 * @param heapq Pointer to the queue to destroy.
 */
void					heapq_destroy(t_heapq *heapq);

/**
 * @brief Inserts a copy of an element into the priority queue.
 * @param heapq Target priority queue.
 * @param data Pointer to the element to copy.
 * @return True on success, false otherwise.
 */
t_bool					heapq_push(t_heapq *heapq, void *data);

/**
 * @brief Removes the highest-priority element from the queue.
 * @param heapq Target priority queue.
 * @param store Buffer to receive the removed element, or NULL to discard it.
 * @return True if an element was removed, false otherwise.
 */
t_bool					heapq_pop(t_heapq *heapq, void *store);

/**
 * @brief Copies the highest-priority element without removing it.
 * @param heapq Target priority queue.
 * @param store Buffer to receive the element.
 * @return True if an element exists, false otherwise.
 */
t_bool					heapq_peek(t_heapq *heapq, void *store);

#endif // !H0NZRA_HEAPQ_H
