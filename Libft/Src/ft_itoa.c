/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:42:50 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:07 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	num;
	size_t	numlen;
	char	*str;

	num = n;
	numlen = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		num = -num;
	}
	else if (n == 0)
		str[--numlen] = '0';
	while (num)
	{
		n = num % 10;
		num /= 10;
		str[--numlen] = (n + '0');
	}
	return (str);
}
