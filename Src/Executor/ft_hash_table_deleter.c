/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_deleter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:09 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:58 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_clear_hash_table(t_hash_table *table)
{
	free(table);
}

void	ft_free_hash_table_helper(t_hash_table *table, size_t index)
{
	t_hash_entity	*entry;
	t_hash_entity	*entity;

	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		entity = entry->next;
		free(entry->key);
		if (table->table->type == ENV)
		{
			free(ft_entity_to_env(entry)->value);
			free(ft_entity_to_env(entry));
		}
		else
			free(ft_entity_to_function(entry));
		entry = entity;
	}
}

void	ft_free_hash_table(t_hash_table *table)
{
	size_t	i;

	if (!table)
		return ;
	i = 0;
	while (i < table->table->capacity)
	{
		ft_free_hash_table_helper(table, i);
		++i;
	}
	free(table->table->entity);
	free(table->table);
	table->table = NULL;
}

void	ft_free_entity_dispatch(t_hash_type type, t_hash_entity *node)
{
	free(node->key);
	if (type == ENV)
	{
		free(ft_entity_to_env(node)->value);
		free(ft_entity_to_env(node));
	}
	else
		free(ft_entity_to_function(node));
}
