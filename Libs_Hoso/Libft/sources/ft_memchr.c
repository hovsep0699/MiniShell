/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 02:18:57 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:27:02 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *source;

	source = (const char *)s;
	while (n)
	{
		if (*source == c)
			return (void *)source;
		++source;
		--n;
	}
	return (NULL);
}
