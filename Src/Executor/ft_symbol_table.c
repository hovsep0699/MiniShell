/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symbol_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:39 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:32 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_symbol_table	*ft_create_symbol_table(char **env)
{
	t_symbol_table	*table;
	char			*shlvl;
	char			*currlvl;

	table = malloc(sizeof(t_symbol_table));
	table->env = ft_create_env(env);
	table->function = ft_create_func_table();
	currlvl = ft_get_env(table->env, "SHLVL");
	shlvl = ft_itoa(ft_atoi(currlvl) + 1);
	ft_set_env(table->env, (t_hash_data){"OLDPWD", NULL, EXPORT});
	ft_set_env(table->env, (t_hash_data){"?", "0", HIDDEN});
	ft_set_env(table->env, (t_hash_data){"SHLVL", shlvl, NORMAL});
	free(shlvl);
	return (table);
}

void	ft_clear_symbol_table(t_symbol_table *table)
{
	if (!table)
		return ;
	ft_free_hash_table(table->env);
	ft_clear_hash_table(table->env);
	ft_free_hash_table(table->function);
	ft_clear_hash_table(table->function);
	free(table);
}
