#ifndef H0NZRA_LIST_H
# define H0NZRA_LIST_H

# include <stdlib.h>

/**
 * @brief Declares an opaque doubly linked list structure.
 */
typedef struct s_list	t_list;

/**
 * @brief Creates an empty list for elements of a fixed size.
 * @param data_size Size in bytes of each element.
 * @return Pointer to the list, or NULL on failure.
 */
t_list					*list_create(size_t data_size);

/**
 * @brief Releases the list and its allocated resources.
 * @param list Pointer to the list to destroy.
 */
void					list_destroy(t_list *list);

/**
 * @brief Appends a copy of an element to the list.
 * @param list Target list
 * @param data Pointer to the element to copy.
 * @return 1 on success, 0 otherwise.
 */
int						list_push_back(t_list *list, void *data);

/**
 * @brief Removes the last element from the list.
 * @param list Target list
 * @param store Buffer for the removed element, or NULL to discard it.
 * @return 1 if an element was removed, 0 otherwise.
 */
int						list_pop_back(t_list *list, void *store);

/**
 * @brief Prepends a copy of an element to the list.
 * @param list Target list; @param data Pointer to the element to copy.
 * @return 1 on success, 0 otherwise.
 */
int						list_push_front(t_list *list, void *data);

/**
 * @brief Removes the first element from the list.
 * @param list Target list
 * @param store Buffer for the removed element, or NULL to discard it.
 * @return 1 if an element was removed, 0 otherwise.
 */
int						list_pop_front(t_list *list, void *store);

/**
 * @brief Checks whether the list is empty.
 * @param list Pointer to the list to check.
 * @return 1 if the list is empty or NULL, 0 otherwise.
 */
int						list_is_empty(const t_list *list);

/**
 * @brief Checks whether the list contains a cycle.
 * @param list Pointer to the list to check.
 * @return 1 if a cycle exists, 0 otherwise.
 */
int						list_have_loop(const t_list *list);

#endif // !H0NZRA_LIST_H
