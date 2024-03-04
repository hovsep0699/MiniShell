/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:50:10 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:17 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_unset(t_command *command, t_symbol_table *table)
{
	if (command->argument && command->argument->arguments && \
		command->argument->arguments[0] && \
		command->argument->arguments[1])
		ft_pop_entity(table->env, command->argument->arguments[1]);
	return (EXIT_SUCCESS);
}
