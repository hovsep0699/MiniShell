/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fix_errors3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:55:57 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 22:27:14 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fname_null(struct s_dict *dict, int fd)
{
	dict->fr_command = FNONE;
	g_signal.exit_status = 258;
	close(fd);
	return (g_signal.exit_status);
}

void	external_error_print(char *data)
{
	ft_putstr_fd("sh: ", STDERR_FILENO);
	ft_putstr_fd(data, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
}

int	ret_valu(t_dict *dict)
{
	return (dict->util_commant == DREAD);
}

int	ret_other(t_dict *dict)
{
	return (dict->type_command == FDREAD);
}

int	ft_print_cd(int err)
{
	g_signal.exit_status = err;
	ft_putendl_fd(strerror(errno), 2);
	return (errno);
}
