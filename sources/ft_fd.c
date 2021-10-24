/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:16 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 12:45:18 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fd_open(t_dict *command)
{
	dup2(command->fd[0], STDIN_FILENO);
	dup2(command->fd[1], STDOUT_FILENO);
	return (SUCCESS);
}
