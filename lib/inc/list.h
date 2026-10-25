/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:31:28 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 18:05:25 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "utils.h"
# include <stdlib.h>

typedef struct s_list	t_list;

t_list					*list_create(size_t data_size);
void					list_destroy(t_list *list);

t_bool					list_push_back(t_list *list, void *data);
t_bool					list_pop_back(t_list *list, void *store);

t_bool					list_push_front(t_list *list, void *data);
t_bool					list_pop_front(t_list *list, void *store);

#endif // !LIST_H
