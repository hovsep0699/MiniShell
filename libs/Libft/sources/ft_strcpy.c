/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:22:57 by mgarcia-          #+#    #+#             */
/*   Updated: 2021/03/23 16:31:31 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int index;

	index = 0;
	while (*src)
	{
		dest[index] = *src;
		++index;
		++src;
	}
	dest[index] = '\0';
	return (dest);
}
