/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_inserter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:03 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:04 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_push_entity(t_hash_entity_list *lst, t_hash_data data, \
						t_hash_type type)
{
	t_hash_entity	*node;

	if (type == FUNCTION)
		node = ft_function_to_entity(\
				ft_create_function_entity(data.key, data.data));
	else
		node = ft_env_to_entity(ft_create_env_entity(data));
	if (!lst->head)
	{
		lst->head = node;
		lst->tail = node;
		++lst->size;
		return ;
	}
	node->next = lst->head;
	lst->head = node;
	++lst->size;
}

void	ft_resize_entity_helper(size_t i, t_hash_table *table, \
				t_entity_table *hash_table, size_t new_capacity)
{
	size_t			index;
	t_hash_entity	*node;
	t_hash_data		data;

	node = table->table->entity[i].head;
	data.type = 0;
	while (node)
	{
		data.key = node->key;
		if (table->table->type == FUNCTION)
			data.data = ft_entity_to_function(node)->function;
		else
		{
			data.data = ft_entity_to_env(node)->value;
			data.type = ft_entity_to_env(node)->visibility;
		}
		index = ft_hash_entity(new_capacity, data.key);
		ft_push_entity(&hash_table->entity[index], data, table->table->type);
		node = node->next;
		++hash_table->size;
	}
}

void	ft_resize_entity(t_hash_table *table, size_t new_capacity)
{
	size_t			i;
	t_entity_table	*hash_table;

	i = 0;
	hash_table = ft_init_entity_table(new_capacity, table->table->type);
	while (i < table->table->capacity)
	{
		ft_resize_entity_helper(i, table, hash_table, new_capacity);
		++i;
	}
	ft_free_hash_table(table);
	table->table = hash_table;
}

void	ft_insert_entity(t_hash_table *table, t_hash_data data)
{
	size_t	index;
	size_t	new_capacity;

	if (!table)
		return ;
	if (table->table->size >= table->table->capacity)
	{
		if (!table->table->capacity)
			new_capacity = 10;
		else
			new_capacity = table->table->capacity * 2;
		ft_resize_entity(table, new_capacity);
	}
	index = ft_hash_entity(table->table->capacity, data.key);
	ft_push_entity(&table->table->entity[index], data, table->table->type);
	++table->table->size;
}

void	ft_set_env(t_hash_table *table, t_hash_data data)
{
	size_t			index;
	t_hash_entity	*entry;
	t_env_entity	*ent_tmp;

	if (!data.key || !*data.key)
		return ;
	index = ft_hash_entity(table->table->capacity, data.key);
	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->key, data.key))
		{
			ent_tmp = ft_entity_to_env(entry);
			free(ent_tmp->value);
			if (data.data)
				ent_tmp->value = ft_strdup(data.data);
			else
				ent_tmp->value = NULL;
			ent_tmp->visibility = data.type;
			return ;
		}
		entry = entry->next;
	}
	ft_insert_entity(table, data);
}
