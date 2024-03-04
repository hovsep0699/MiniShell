/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:54:40 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:12:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while ((ptr1[i] != '\0' || ptr2[i] != '\0') && i < n)
	{
		if (ptr1[i] > ptr2[i])
			return (1);
		else if (ptr1[i] < ptr2[i])
			return (-1);
		i++;
	}
	return (0);
}
