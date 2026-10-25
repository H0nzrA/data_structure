/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_utility.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 15:24:14 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:15:41 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAPQ_UTILITY_H
# define HEAPQ_UTILITY_H

# include "heapq.h"
# include <stdlib.h>

/**
 * @brief Restores the heap property by moving an element upward.
 * @param heapq Priority queue to modify.
 * @param index Index of the element to reposition.
 */
void	heapqu_shift_up(t_heapq *heapq, size_t index);

/**
 * @brief Restores the heap property by moving an element downward.
 * @param heapq Priority queue to modify.
 * @param index Index of the element to reposition.
 */
void	heapqu_shift_down(t_heapq *heapq, size_t index);

/**
 * @brief Swaps two elements in the priority queue.
 * @param heapq Priority queue containing the elements.
 * @param a Index of the first element.
 * @param b Index of the second element.
 */
void	heapqu_swap(t_heapq *heapq, size_t a, size_t b);

/**
 * @brief Calculates the parent index of a node.
 * @param index Index of the node.
 * @return Index of the parent node.
 */
size_t	heapqu_parent_node(size_t index);

/**
 * @brief Calculates the right child index of a node.
 * @param index Index of the parent node.
 * @return Index of the right child node.
 */

size_t	heapqu_right_node(size_t index);

/**
 * @brief Calculates the left child index of a node.
 * @param index Index of the parent node.
 * @return Index of the left child node.
 */
size_t	heapqu_left_node(size_t index);

#endif // !HEAPQ_UTILITY_H
