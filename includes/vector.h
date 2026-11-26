#ifndef H0NZRA_VECTOR_H
# define H0NZRA_VECTOR_H

# include <stdlib.h>

/**
 * @brief Represent a generic dynamic array.
 */
typedef struct s_vector	t_vector;

/**
 * @brief Creates and empty vector for elements of fixed size.
 * @param data_size Size in bytes of each elements.
 * @return Pointer to the list, or NULL on failure.
 */
t_vector				*vector_create(size_t data_size);

/**
 * @brief Release the vector and free its allocated resources.
 * @param vector Vector to destroy.
 */
void					vector_destroy(t_vector *vector);

/**
 * @brief Add elements to the back of the vector.
 * @param vector Vector to modify.
 * @param data Element to copy into the queue.
 * @return 1 on success, 0 on failure.
 */
int						vector_push(t_vector *vector, void *data);

/**
 * @brief Remove the last element from the vector.
 * @param vector Vector to modify.
 * @param store Buffer for the removed element, or NULL to discard it.
 * @return 1 if an element was removed, 0 otherwise.
 */
int						vector_pop(t_vector *vector, void *store);

/**
 * @brief Return the number of element in the vector.
 * @param vector Vector to inspect.
 * @return Number of element in the vector.
 */
size_t					vector_size(t_vector *vector);

/**
 * @brief Get the current capacity of the vector.
 * @param vector Vector to query
 * @return Number of element the vector can hold withoud reallocation.
 */
size_t					vector_capacity(t_vector *vector);

/**
 * @brief Checke whether the vector is empty.
 * @param vector Vector to inspect.
 * @return 1 if empty, 0 otherwise.
 */
int						vector_is_empty(t_vector *vector);

/**

	* @brief Remove all the element from the vector without releasing its allocated memory.
 * @param vector Vector to clear.
 */
void					vector_clear(t_vector *vector);

/**
 * @brief Replace the element at specific index.
 * @param vector Vector to modify.
 * @param index Index of the elment to replace.
 * @param data The new element data.
 * @return 1 on success, 0 otherwise.
 */
int						vector_set(t_vector *vector, size_t index, void *data);

/**
 * @brief Copy the element at a specific index to the provided storage.
 * @param vector Vector to modify.
 * @param index Index of the element to copy.
 * @param store Destination storage for the copied element.
 * @return 1 on success, 0 otherwise.
 */
int						vector_get(t_vector *vector, size_t index, void *store);

/**
 * @brief Ensure the vector has at least the specific capacity.
 * @param vector Vector to reserve capacity for.
 * @param reserve Minimum capacity to allcoate.
 * @return 1 on success, 0 otherwise
 */
int						vector_reserve(t_vector *vector, size_t reserve);

#endif // !H0NZRA_VECTOR_H
