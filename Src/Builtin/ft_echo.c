/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:49:04 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:13:45 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_echo_isnoprint(char *argument)
{
	int		option_n;
	size_t	i;

	option_n = 0;
	i = 1;
	if (argument[0] == '-')
	{
		option_n = 0;
		while (argument[i])
		{
			if (argument[i] != 'n')
			{
				option_n = 1;
				break ;
			}
			++i;
		}
		if (!option_n)
			return (0);
	}
	return (1);
}

int	ft_echo(t_command *command, t_symbol_table *table)
{
	int		is_new_line;
	size_t	i;

	(void)table;
	is_new_line = 1;
	i = 0;
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0] && command->argument->arguments[1])
		is_new_line = ft_echo_isnoprint(command->argument->arguments[1]);
	i = 1;
	while (!is_new_line && command->argument->arguments[i] && \
		command->argument->arguments[i][0] == '-' && \
		command->argument->arguments[i][1] == 'n')
		++i;
	while (command->argument->arguments[i])
	{
		ft_putstr_fd(command->argument->arguments[i], STDOUT_FILENO);
		if (command->argument->arguments[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		++i;
	}
	if (is_new_line)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
