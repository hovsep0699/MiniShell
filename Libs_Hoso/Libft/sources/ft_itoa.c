/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:30:44 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:24:15 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_digit_count(long num)
{
	size_t count;

	count = 0;
	while (num)
	{
		++count;
		num /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	long	nb;
	size_t	count;
	char	*str;

	nb = (long)n;
	count = ft_num_digit_count(nb);
	count = (n < 0) ? count + 2 : count + 1;
	if (n == 0)
		++count;
	if (!(str = (char *)malloc((count) * sizeof(char))))
		return (NULL);
	nb = (n < 0) ? -(long)n : (long)n;
	str[count - 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (count - 1)
	{
		str[count - 2] = nb % 10 + '0';
		str[0] = (n < 0) ? '-' : nb % 10 + '0';
		nb /= 10;
		--count;
	}
	return (str);
}
