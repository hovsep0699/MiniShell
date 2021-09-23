/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 02:22:46 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:27:11 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *mem1;
	unsigned char *mem2;

	mem2 = (unsigned char *)s2;
	mem1 = (unsigned char *)s1;
	while (n)
	{
		if (*mem1 != *mem2)
			return (*mem1 - *mem2);
		++mem1;
		++mem2;
		--n;
	}
	return (0);
}
