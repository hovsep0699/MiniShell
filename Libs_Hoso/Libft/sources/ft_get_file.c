/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:01:55 by hohayrap          #+#    #+#             */
/*   Updated: 2021/08/14 15:13:54 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_get_file(file_t *file)
{
	char	*line;
	char	*content;
	int		gnl_ret;

	content = NULL;
	while ((gnl_ret = ft_getline(file->fd, &line)))
	{
		if (gnl_ret == -1)
			return ;
		content = ft_realloc_strjoin(content, line);
		ft_strdel(&line);
		++file->rows;
	}
	if (!content)
		return ;
	ft_strdel(&line);
	file->size = ft_zero_byte_strlen(content);
	file->content = ft_strsplit(content, '\n');
}

