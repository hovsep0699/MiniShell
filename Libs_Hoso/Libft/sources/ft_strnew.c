/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:17:03 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/23 23:17:13 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size)
	{
		str[size] = '\0';
		--size;
	}
	return str;
}

