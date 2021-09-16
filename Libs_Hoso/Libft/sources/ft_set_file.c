/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:48:21 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/25 16:44:49 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_set_file(file_t *file, file_t *out, char *filepath, char *mode)
{
	int		index;

	if (!ft_strcmp(mode, "r"))
		return ;
	out = ft_fopen(filepath, mode);
	if (!out || !file->content)
		return ;
	index = -1;
	while (file->content[++index])
		ft_putendl_fd(file->content[index], out->fd);
	ft_fclose(out);
}

void	ft_set_file2(char **content, file_t *out, char *filepath, char *mode)
{
	int		index;

	if (!ft_strcmp(mode, "r"))
		return ;
	out = ft_fopen(filepath, mode);
	if (!out || !content)
		return ;
	index = -1;
	while (content[++index])
		ft_putendl_fd(content[index], out->fd);
	ft_fclose(out);
}
