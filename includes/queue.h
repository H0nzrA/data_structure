#ifndef H0NZRA_QUEUE_H
# define H0NZRA_QUEUE_H

# include <stdlib.h>

# ifdef __cplusplus
extern "C" {
# endif

/**
 * @brief Represent a generic FIFO queue.
 */
typedef struct s_queue	t_queue;

/**
 * @brief Create an empty queue for elements for the specific size.
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
 * @return 1 on success, 0 on failure.
 */
int						queue_enqueue(t_queue *queue, const void *data);

/**
 * @brief Removes and retrieves the first element of the queue.
 * @param queue Queue to modify.
 * @param store Buffer to store the removed element, or NULL to discard it.
 * @return 1 on success, 0 if the queue is empty of an error occured.
 */
int						queue_dequeue(t_queue *queue, void *store);

/**
 * @brief Retrieves the front element without removing it.
 * @param queue Queue to inspect.
 * @param store Buffer to store the retrieved element.
 * @return 1 on success, 0 if the queue is empty of an error occured.
 */
int						queue_peek(const t_queue *queue, void *store);

/**
 * @brief Check whether the queue contain no elements.
 * @param queue Queue to inspect.
 * @return 1 if empty, 0 otherwise.
 */
int						queue_is_empty(const t_queue *queue);

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

# ifdef __cplusplus
}
# endif

#endif // !H0NZRA_QUEUE_H
