/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_rowslen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:33:17 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/24 17:37:20 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_file_rowslen(int fd)
{
	int length;
	int ret;
	char *line;

	if (fd < 0)
		return -1;
	length = -1;
	while ((ret = ft_getline(fd, &line)))
	{
		if (ret == -1)
			return (-1);
		++length;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return length;
}

