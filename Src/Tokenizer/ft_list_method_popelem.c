/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_method_popelem.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:02:45 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:17:44 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_free_tok(t_token **token)
{
	free((*token)->token);
	free(*token);
}

void	ft_pop_front(t_list_token *list)
{
	t_token	*tmp;

	if (list == NULL || list->head == NULL)
		return ;
	if (list->size == 1)
		list->tail = NULL;
	tmp = list->head;
	list->head = (list->head)->next;
	if (list->head)
		list->head->prev = NULL;
	free(tmp->token);
	free(tmp);
	--list->size;
}

void	ft_pop_back(t_list_token *list)
{
	t_token	*tmp;
	t_token	*prev;

	if (list == NULL || list->head == NULL)
		return ;
	tmp = list->head;
	prev = NULL;
	while (tmp && tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev == NULL)
	{
		ft_free_tok(&tmp);
		list->head = NULL;
	}
	else
	{
		prev->next = NULL;
		ft_free_tok(&tmp);
	}
	list->tail = prev;
	--list->size;
}

void	ft_free_list(t_list_token *list)
{
	t_token	*tmp;
	t_token	*next;

	if (list == NULL)
		return ;
	if (list->head == NULL)
	{
		free(list);
		return ;
	}
	tmp = list->head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->token);
		free(tmp);
		tmp = next;
	}
	list->head = NULL;
	list->size = 0;
	free(list);
}

void	ft_print_list(t_token *list)
{
	t_token		*current;

	current = list;
	while (current)
	{
		printf("Type: %u, Token: %s\n", current->type, current->token);
		current = current->next;
	}
}
