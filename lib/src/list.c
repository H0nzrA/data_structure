/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:35:18 by trakotoz          #+#    #+#             */
/*   Updated: 2026/10/25 18:34:26 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "list_internal.h"
#include <stdlib.h>

t_list	*list_create(size_t data_size)
{
	t_list *list;

	if (!data_size)
		return (NULL);
	list = (t_list *) malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->data_size = data_size;
	return (list);
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
	free(list);
}
