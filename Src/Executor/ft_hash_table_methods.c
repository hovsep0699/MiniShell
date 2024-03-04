/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_methods.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:31 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:07 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_entity_table	*ft_init_entity_table(size_t initialCapacity, t_hash_type type)
{
	size_t			i;
	t_entity_table	*table;

	table = (t_entity_table *)malloc(sizeof(t_entity_table));
	table->size = 0;
	table->capacity = initialCapacity;
	if (!initialCapacity)
		table->entity = NULL;
	else
	{
		i = 0;
		table->entity = malloc(initialCapacity * sizeof(t_hash_entity_list));
		while (i < initialCapacity)
			ft_init_entity_list(&table->entity[i++]);
	}
	table->type = type;
	return (table);
}

t_hash_table	*ft_init_hash_table(size_t initialCapacity, t_hash_type type)
{
	t_hash_table	*table;

	table = malloc(sizeof(t_hash_table));
	table->table = ft_init_entity_table(initialCapacity, type);
	return (table);
}

void	ft_init_entity_list(t_hash_entity_list	*list)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

size_t	ft_hash_entity(size_t capacity, char *key)
{
	size_t	i;
	size_t	hash_value;

	i = 0;
	hash_value = 0;
	while (i < ft_strlen(key))
		hash_value += key[i++];
	return (hash_value % capacity);
}
