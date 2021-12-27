/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_welcome.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:22 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 15:47:45 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_welcome(char *path)
{
	ft_putstr(path);
}

int	print_pipe(int pipe_count)
{
	while (pipe_count - 1)
	{
		ft_putstr("pipe ");
		pipe_count--;
	}
	ft_putstr("pipe> ");
	return (0);
}

void	export_error(char *str_exeption)
{
	ft_putstr_fd("export: not an identifier: ", 2);
	ft_putstr_fd(str_exeption, 2);
	ft_putchar_fd('\n', 2);
}

void	errno_print(char *ernno_str)
{
	ft_putstr_fd(ernno_str, 2);
	ft_putchar_fd('\n', 2);
}

void	file_errno(char *ernno_str, char *name_file)
{
	ft_putstr_fd("sh: ", 2);
	ft_putstr_fd(ernno_str, 2);
	ft_putchar_fd(':', 2);
	ft_putstr_fd(name_file, 2);
	ft_putchar_fd('\n', 2);
}
