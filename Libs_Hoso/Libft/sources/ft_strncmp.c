/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 03:46:21 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:35:51 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (--n && *str1 && *str2 && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	if (*str1 == *str2)
		return (0);
	return (*str1 > *str2 ? 1 : -1);
}
