/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_to_env_converter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:20 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:13 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_convert_env_helper(char *tok, int mode, char *value)
{
	tok = ft_gnl_strjoin(tok, "=");
	if (mode)
		tok = ft_gnl_strjoin(tok, "\"");
	tok = ft_gnl_strjoin(tok, value);
	if (mode)
		tok = ft_gnl_strjoin(tok, "\"");
	return (tok);
}

void	ft_iterate_hash(t_hash_iterate *it, t_hash_table_arr *arr)
{
	t_hash_entity	*entry;
	t_env_entity	*node;

	entry = it->entity;
	while (entry != NULL)
	{
		node = ft_entity_to_env(entry);
		if (node->visibility == it->visibility || node->visibility == NORMAL)
		{
			arr->table[it->pos] = ft_strdup(node->base.key);
			if (node->value)
				arr->table[it->pos] = ft_convert_env_helper(\
					arr->table[it->pos], it->mode, node->value);
			++it->pos;
		}
		entry = entry->next;
	}
}

t_hash_table_arr	ft_convert_env_to_args(t_hash_table *env, \
						t_visibility_type visibility, int mode)
{
	t_hash_table_arr	arr;
	t_hash_iterate		it;
	size_t				i;

	i = 0;
	it.pos = 0;
	arr.table = ft_calloc(env->table->size + 1, sizeof(char *));
	while (i < env->table->capacity)
	{
		it.entity = env->table->entity[i].head;
		it.mode = mode;
		it.visibility = visibility;
		ft_iterate_hash(&it, &arr);
		++i;
	}
	arr.size = it.pos;
	return (arr);
}
