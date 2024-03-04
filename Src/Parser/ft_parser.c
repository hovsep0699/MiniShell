/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:56:54 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:16:19 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_io	ft_init_io(void)
{
	t_io	io;

	io.input = 0;
	io.output = 1;
	io.error = 2;
	return (io);
}

t_io	ft_init_io_std(void)
{
	t_io	io;

	io.error = dup(STDERR_FILENO);
	io.input = dup(STDIN_FILENO);
	io.output = dup(STDOUT_FILENO);
	return (io);
}

t_container	ft_parser(t_container cont, t_list_token *list)
{
	t_container	container;

	container = ft_sematic(cont, list);
	container.fd = ft_init_io_std();
	return (container);
}
