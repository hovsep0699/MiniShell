/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_error3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:03:01 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 22:26:22 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_norm_error(char **line, int in_fd, int out_fd)
{
	ft_pipe_close(in_fd);
	ft_pipe_close(out_fd);
	ft_strdel(line);
}

void	ft_put_env_norm(char *item, char *key)
{
	ft_putstr_fd(key, 1);
	ft_putstr_fd("=", 1);
	if (item != NULL && item[0] != '\0')
		ft_putstr_fd(item, 1);
	else
		ft_putstr_fd("", 1);
	ft_putchar_fd('\n', 1);
}

char	*to_void(char **envp, char **data, int count, t_dict *dict)
{
	(void)envp;
	(void)data;
	(void)count;
	dict->fr_command = FNONE;
	return (NULL);
}
