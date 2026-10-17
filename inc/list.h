/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:31:28 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/17 13:37:57 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "utils.h"
# include <stdlib.h>

typedef struct s_node
{
	unsigned char	*content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
	size_t			data_size;
}					t_list;

void				list_init(t_list *list, size_t data_size);
void				list_destroy(t_list *list);

t_bool				list_push_back(t_list *list, void *data);
t_bool				list_pop_back(t_list *list, void *store);

t_bool				list_push_front(t_list *list, void *data);
t_bool				list_pop_front(t_list *list, void *store);

#endif // !LIST_H
