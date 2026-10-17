/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:35:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/17 13:55:31 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	list_init(t_list *list, size_t data_size)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->data_size = data_size;
}

void	list_destroy(t_list *list)
{
	t_node	*node;
	t_node	*next;

	if (!list)
		return ;
	node = list->head;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->data_size = 0;
}
