/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 19:06:46 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/01 12:03:34 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H0NZRA_QUEUE_H
# define H0NZRA_QUEUE_H

# include "utils.h"
# include <stdlib.h>

/**
 * @brief Represent a generic FIFO queue.
 */
typedef struct s_queue	t_queue;

/**
 * @brief Create an empty for elements for the specific size.
 * @param data_size Size in bytes of each elements.
 * @return A pointer to the queue, NULL on failure.
 */
t_queue					*queue_create(size_t data_size);

/**
 * @brief Destroys a queue and free its allocated resources.
 * @param queue Queue to destroy.
 */
void					queue_destroy(t_queue *queue);

/**
 * @brief Adds an element to the back of queue.
 * @param queue Queue to modify.
 * @param data Element to copy into the queue.
 * @return True on success, False on failure.
 */
t_bool					queue_enqueue(t_queue *queue, const void *value);

/**
 * @brief Removes and retrieves the first element of the queue.
 * @param queue Queue to modify.
 * @param store Buffer to store the removed element, or NULL to discard it.
 * @return True on success, False if the queue is empty of an error occured.
 */
t_bool					queue_dequeue(t_queue *queue, void *store);

/**
 * @brief Retrieves the front element without removing it.
 * @param queue Queue to inspect.
 * @param store Buffer to store the retrieved element.
 * @return True on success, False if the queue is empty of an error occured.
 */
t_bool					queue_peek(const t_queue *queue, void *store);

/**
 * @brief Check whether the queue contain no elements.
 * @param queue Queue to inspect.
 * @return True if empty, False otherwise.
 */
t_bool					queue_is_empty(const t_queue *queue);

/**
 * @brief Returns the number of elements in the queue.
 * @param queue Queue to inspect.
 * @return Number of element.
 */
size_t					queue_size(const t_queue *queue);

/**
 * @brief Removes all elements from the queue without destroying it.
 * @param queue Queue to clear.
 */
void					queue_clear(t_queue *queue);

#endif // !H0NZRA_QUEUE_H
