/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_getters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:05 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:00 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_function_callback	ft_get_function(t_hash_table *table, char *key)
{
	size_t			index;
	t_hash_entity	*entry;

	if (!key || !*key)
		return (NULL);
	index = ft_hash_entity(table->table->capacity, key);
	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->key, key))
			return (ft_entity_to_function(entry)->function);
		entry = entry->next;
	}
	return (NULL);
}

t_function_entity	*ft_get_function_entity(t_hash_table *table, char *key)
{
	size_t			index;
	t_hash_entity	*entry;

	if (!key || !*key)
		return (NULL);
	index = ft_hash_entity(table->table->capacity, key);
	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->key, key))
			return (ft_entity_to_function(entry));
		entry = entry->next;
	}
	return (NULL);
}

t_env_entity	*ft_get_env_entity(t_hash_table *table, char *key)
{
	size_t			index;
	t_hash_entity	*entry;

	if (!key || !*key)
		return (NULL);
	index = ft_hash_entity(table->table->capacity, key);
	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->key, key))
			return (ft_entity_to_env(entry));
		entry = entry->next;
	}
	return (NULL);
}

char	*ft_get_env(t_hash_table *table, char *key)
{
	size_t			index;
	t_hash_entity	*entry;

	if (!key || !*key)
		return (NULL);
	index = ft_hash_entity(table->table->capacity, key);
	entry = table->table->entity[index].head;
	while (entry != NULL)
	{
		if (!ft_strcmp(entry->key, key))
			return (ft_entity_to_env(entry)->value);
		entry = entry->next;
	}
	return (NULL);
}
