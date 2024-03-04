/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_method_pushelem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:55:23 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:47 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_list_token	*ft_init_list(void)
{
	t_list_token	*list;

	list = (t_list_token *)malloc(sizeof(t_list_token));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	ft_init_token(t_token *node, int type, char *elem)
{
	node->quate_type = 0;
	node->type = type;
	node->token = elem;
	node->next = NULL;
	node->prev = NULL;
}

void	ft_push_back(t_list_token *list, int type, const char *token)
{
	t_token	*new;
	t_token	*tmp;

	if (!list)
		return ;
	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return ;
	ft_init_token(new, type, ft_strdup(token));
	if (list->head == NULL)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		tmp = list->head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		list->tail = new;
	}
	++list->size;
}

void	ft_push_front(t_list_token *list, int type, const char *token)
{
	t_token	*new;

	if (!list)
		return ;
	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return ;
	ft_init_token(new, type, ft_strdup(token));
	if (!list->head)
	{
		list->head = new;
		list->tail = new;
		++list->size;
		return ;
	}
	new->next = list->head;
	list->head->prev = new;
	list->head = new;
	++list->size;
}
