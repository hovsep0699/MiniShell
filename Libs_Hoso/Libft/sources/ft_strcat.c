/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:22:29 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:30:11 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int index;

	index = 0;
	while (dest[index])
		++index;
	while (*src)
	{
		dest[index] = *src;
		++index;
		++src;
	}
	dest[index] = '\0';
	return (dest);
}
