/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:42:38 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:10 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	print_env(t_hash_table *env, t_visibility_type visibility)
{
	size_t			i;
	t_hash_entity	*entry;
	t_env_entity	*node;

	i = 0;
	while (i < env->table->capacity)
	{
		entry = env->table->entity[i].head;
		while (entry != NULL)
		{
			node = ft_entity_to_env(entry);
			if (node->visibility == visibility || node->visibility == NORMAL)
				printf("%s=%s\n", entry->key, node->value);
			entry = entry->next;
		}
		++i;
	}
}

void	ft_handle_env_key_part(t_hash_data data, t_hash_table *table)
{
	if (!ft_strcmp(data.key, "_"))
	{
		data.type = VENV;
		ft_insert_entity(table, data);
	}
	else
	{
		data.type = NORMAL;
		ft_insert_entity(table, data);
	}
}

void	ft_pop_entity_helper(t_hash_entity_list *lst, char *key, \
								t_hash_table *table)
{
	t_hash_entity	*entry;
	t_hash_entity	*node;
	t_hash_entity	*tmp;

	entry = lst->head;
	node = lst->head;
	while (entry)
	{
		if (!ft_strcmp(entry->key, key))
			break ;
		node = entry;
		entry = entry->next;
	}
	if (entry && !ft_strcmp(entry->key, key))
	{
		tmp = entry;
		node->next = tmp->next;
		if (tmp == lst->tail)
			lst->tail = node;
		ft_free_entity_dispatch(table->table->type, tmp);
	}
}

void	ft_pop_entity(t_hash_table *table, char *key)
{
	size_t				index;
	t_hash_entity_list	*lst;

	if (!table)
		return ;
	if (ft_get_env_entity(table, key)->visibility == HIDDEN)
		return ;
	index = ft_hash_entity(table->table->capacity, key);
	lst = &table->table->entity[index];
	if (!lst || !lst->head)
		return ;
	if (!ft_strcmp(lst->head->key, key))
	{
		ft_free_entity_dispatch(table->table->type, lst->head);
		lst->head = NULL;
		lst->tail = NULL;
	}
	else
		ft_pop_entity_helper(lst, key, table);
	--lst->size;
}

void	print_env_table(t_hash_table_arr arr)
{
	size_t	i;

	i = 0;
	while (arr.table && arr.table[i])
	{
		ft_putstr_fd("declare -X ", STDOUT_FILENO);
		ft_putstr_fd(arr.table[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		++i;
	}
}
