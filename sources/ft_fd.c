/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:16 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/04 20:59:06 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fd_open(t_dict *command)
{
	dup2(command->fd[0], STDIN_FILENO);
	dup2(command->fd[1], STDOUT_FILENO);
	return (SUCCESS);
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
