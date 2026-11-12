/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:14:01 by trakotoz          #+#    #+#             */
/*   Updated: 2026/11/12 20:20:40 by trakotoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "list_internal.h"
#include "utils.h"
#include <string.h>
#include <stdlib.h>

t_bool	list_push_back(t_list *list, void *data)
{
	t_node	*node;

	if (!list || !data)
		return (False);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (False);
	node->content = (unsigned char *)malloc(list->data_size);
	if (!node->content)
	{
		free(node);
		return (False);
	}
	memcpy(node->content, data, list->data_size);
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	else
		list->head = node;
	list->tail = node;
	list->size++;
	return (True);
}

t_bool	list_push_front(t_list *list, void *data)
{
	t_node	*node;

	if (!list || !data)
		return (False);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (False);
	node->content = (unsigned char *)malloc(list->data_size);
	if (!node->content)
	{
		free(node);
		return (False);
	}
	memcpy(node->content, data, list->data_size);
	node->prev = NULL;
	node->next = list->head;
	if (list->head)
		list->head->prev = node;
	else
		list->tail = node;
	list->head = node;
	list->size++;
	return (True);
}

t_bool	list_pop_back(t_list *list, void *store)
{
	t_node	*last;

	if (!list || !list->tail)
		return (False);
	if (store)
		memcpy(store, list->tail->content, list->data_size);
	last = list->tail;
	list->tail = last->prev;
	if (list->tail)
		list->tail->next = NULL;
	else
		list->head = NULL;
	free(last->content);
	free(last);
	list->size--;
	return (True);
}

t_bool	list_pop_front(t_list *list, void *store)
{
	t_node	*head;

	if (!list || !list->head)
		return (False);
	if (store)
		memcpy(store, list->head->content, list->data_size);
	head = list->head;
	list->head = head->next;
	if (list->head)
		list->head->prev = NULL;
	else
		list->tail = NULL;
	free(head->content);
	free(head);
	list->size--;
	return (True);
}

t_bool	list_is_empty(const t_list *list)
{
	if (!list)
		return (True);
	return (list->size == 0);
}

t_bool	list_have_loop(const t_list *list)
{
	t_node	*tortois;
	t_node	*hare;

	if (!list)
		return (False);
	tortois = list->head;
	hare = list->head;
	while (hare && hare->next)
	{
		tortois = tortois->next;
		hare = hare->next->next;
		if (tortois == hare)
			return (True);
	}
	return (False);
}
