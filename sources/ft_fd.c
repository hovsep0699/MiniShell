/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:16 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 18:55:55 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fd_open(t_dict *command)
{
	dup2(command->fd[0], STDIN_FILENO);
	dup2(command->fd[1], STDOUT_FILENO);
	return (SUCCESS);
}

int	ft_ret_end(t_dict *command)
{
	char	*old_pwd;

	ft_strdel(&command->data);
	old_pwd = find_data("OLDPWD", command->variable_dic);
	if (old_pwd == NULL)
	{
		g_signal.exit_status = 1;
		ft_putstr_fd("sh: OLDPWD not set\n", 2);
		return (0);
	}
	command->data = ft_strdup(old_pwd);
	ft_putendl(command->data);
	return (1);
}

char	**av_ret(char *tmp_path, char **data_sp)
{
	char	**av;

	av = ft_vecstrinit(2);
	av[0] = ft_strdup(tmp_path);
	av[1] = NULL;
	if (data_sp[0] != NULL)
		av = ft_fvecstrcpy(av, data_sp);
	return (av);
}

int	ft_setechoopt(t_dict *dict)
{
	if (ft_zero_byte_strlen(dict->data) != 0)
		return (0);
	dict->echo_option = 1;
	dict->icom++;
	return (1);
}
