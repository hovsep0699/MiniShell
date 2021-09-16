/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filememdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:46:12 by hohayrap          #+#    #+#             */
/*   Updated: 2021/08/25 22:13:57 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_file_destructor(file_t *file)
{
	if (!file)
		return ;
	ft_vecstrdel(&file->content);
	ft_memdel((void **)&file);
	file = NULL;
}
