/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table_creators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:30 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:55 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_env_entity	*ft_create_env_entity(t_hash_data data)
{
	t_env_entity	*node;

	node = (t_env_entity *)malloc(sizeof(t_env_entity));
	node->base.key = ft_strdup(data.key);
	if ((char *)data.data)
		node->value = ft_strdup((char *)data.data);
	else
		node->value = NULL;
	node->visibility = data.type;
	node->base.next = NULL;
	return (node);
}

char	*ft_create_env_helper(t_hash_table *table, char	**env, size_t i)
{
	char			*assign;
	size_t			len;
	t_hash_data		data;

	assign = ft_strchr(env[i], '=');
	if (assign)
	{
		len = assign - env[i];
		data.data = assign + 1;
	}
	else
	{
		len = ft_strlen(env[i]);
		data.data = NULL;
	}
	data.key = ft_substr(env[i], 0, len);
	ft_handle_env_key_part(data, table);
	return (data.key);
}

t_hash_table	*ft_create_env(char **env)
{
	size_t			i;
	t_hash_table	*table;

	i = 0;
	table = ft_init_hash_table(10, ENV);
	while (env && env[i])
	{
		free(ft_create_env_helper(table, env, i));
		++i;
	}
	return (table);
}

t_hash_table	*ft_create_func_table(void)
{
	t_hash_table	*funcs;

	funcs = ft_init_hash_table(7, FUNCTION);
	ft_insert_entity(funcs, (t_hash_data){"exit", ft_exit, 0});
	ft_insert_entity(funcs, (t_hash_data){"cd", ft_cd, 0});
	ft_insert_entity(funcs, (t_hash_data){"echo", ft_echo, 0});
	ft_insert_entity(funcs, (t_hash_data){"env", ft_env, 0});
	ft_insert_entity(funcs, (t_hash_data){"export", ft_export, 0});
	ft_insert_entity(funcs, (t_hash_data){"unset", ft_unset, 0});
	ft_insert_entity(funcs, (t_hash_data){"pwd", ft_pwd, 0});
	ft_insert_entity(funcs, (t_hash_data){"history", ft_history, 0});
	return (funcs);
}

t_function_entity	*ft_create_function_entity(char *key, void *data)
{
	t_function_entity	*node;

	node = (t_function_entity *)malloc(sizeof(t_function_entity));
	node->function = (t_function_callback)data;
	node->base.key = ft_strdup(key);
	node->base.next = NULL;
	return (node);
}
