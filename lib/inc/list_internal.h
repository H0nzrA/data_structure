/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:54:55 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 20:28:55 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

# include "list.h"

/**
 * @brief Represents a node in a doubly linked list.
 */
typedef struct s_node
{
	unsigned char	*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/**
 * @brief Stores the state and metadata of a doubly linked list.
 */
typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
	size_t			data_size;
}					t_list;

#endif // !LIST_INTERNAL_H
