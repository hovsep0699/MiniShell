/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:49:33 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:13:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdint.h>

int	ft_is_numeric(char *str, unsigned char *status)
{
	size_t	i;
	int		is_overflow;

	i = 0;
	is_overflow = 0;
	if (str && str[i] && (str[i] == '-' || str[i] == '+'))
		++i;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	*status = ft_atoll(str, &is_overflow);
	return (!is_overflow);
}

void	ft_handle_exit_args(char **args)
{
	size_t			i;
	unsigned char	st;

	i = 1;
	while (args[i])
	{
		if (!ft_is_numeric(args[i], &st))
		{
			ft_panic_shell("exit: ", "numeric argument required");
			exit(2);
		}
		++i;
	}
}

//TODO handle arguments and non-numerics
int	ft_exit(t_command *command, t_symbol_table *table)
{
	unsigned char	status;

	status = 0;
	(void)table;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0] && \
		command->argument->arguments[1])
	{
		if (command->argument->arguments[2] && \
			ft_is_numeric(command->argument->arguments[1], &status))
		{
			ft_panic_shell("exit: ", "too many arguments");
			return (EXIT_FAILURE);
		}
		ft_handle_exit_args(command->argument->arguments);
		exit (status);
	}
	exit (EXIT_SUCCESS);
}
