/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:49:46 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:03 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_set_export_data(t_hash_table *table, t_hash_data *data)
{
	char	*oldval;

	if (!ft_get_env(table, data->key))
		oldval = ft_strdup("");
	else
		oldval = ft_strdup(ft_get_env(table, data->key));
	oldval = ft_gnl_strjoin(oldval, data->data);
	data->data = oldval;
	ft_set_env(table, *data);
	free(oldval);
}

int	ft_handle_export_ident(char *line, t_hash_table *table)
{
	t_hash_data	data;
	char		*tmp;
	char		plus;
	int			status;

	plus = 0;
	status = EXIT_SUCCESS;
	tmp = ft_export_collect_data(line, &data, &plus);
	if (*data.key && ft_is_valid_identifier(data.key))
	{
		if (plus == '+')
			ft_set_export_data(table, &data);
		else
			ft_set_env(table, data);
	}
	else
		status = EXIT_FAILURE;
	free(tmp);
	free(data.key);
	if (status)
		ft_panic_shell("export: not a valid identifier", "");
	return (status);
}

int	ft_export(t_command *command, t_symbol_table *table)
{
	t_hash_table_arr	arr;
	size_t				i;
	size_t				status;

	status = EXIT_SUCCESS;
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0] && command->argument->arguments[1])
	{
		i = 1;
		while (command->argument->arguments[i])
		{
			status = status | \
			ft_handle_export_ident(command->argument->arguments[i], table->env);
			++i;
		}
		if (status != EXIT_SUCCESS)
			return (status);
	}
	else
	{
		arr = ft_sort_env(table->env);
		print_env_table(arr);
		free(arr.table);
	}
	return (EXIT_SUCCESS);
}
