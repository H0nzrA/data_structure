/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapq_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:43:09 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 21:47:33 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_HEAPQ_INTERNAL_H
# define H0NZRA_HEAPQ_INTERNAL_H

# include "heapq.h"

/**
 * @brief Stores the internal state of a heap-based priority queue.
 */
typedef struct s_heapq
{
	unsigned char	*container;
	size_t			size;
	size_t			capacity;
	size_t			data_size;
	t_compare		func_compare;
	t_heapq_type	type;
}					t_heapq;

/**
 * @brief Restores the heap property by moving an element upward.
 * @param heapq Priority queue to modify.
 * @param index Index of the element to reposition.
 */
void				heapqu_sift_up(t_heapq *heapq, size_t index);

/**
 * @brief Restores the heap property by moving an element downward.
 * @param heapq Priority queue to modify.
 * @param index Index of the element to reposition.
 */
void				heapqu_sift_down(t_heapq *heapq, size_t index);

/**
 * @brief Swaps two elements in the priority queue.
 * @param heapq Priority queue containing the elements.
 * @param a Index of the first element.
 * @param b Index of the second element.
 */
void				heapqu_swap(t_heapq *heapq, size_t a, size_t b);

/**
 * @brief Calculates the parent index of a node.
 * @param index Index of the node.
 * @return Index of the parent node.
 */
size_t				heapqu_parent_node(size_t index);

/**
 * @brief Calculates the right child index of a node.
 * @param index Index of the parent node.
 * @return Index of the right child node.
 */

size_t				heapqu_right_node(size_t index);

/**
 * @brief Calculates the left child index of a node.
 * @param index Index of the parent node.
 * @return Index of the left child node.
 */
size_t				heapqu_left_node(size_t index);

void				heapqu_heapify(t_heapq *heapq);

#endif // !H0NZRA_HEAPQ_INTERNAL_H
