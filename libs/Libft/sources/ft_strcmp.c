/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:23:49 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:30:58 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int index;

	index = 0;
	while (str1[index] == str2[index] && str1[index] && str2[index])
		++index;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
