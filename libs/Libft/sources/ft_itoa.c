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
	size_t	count;

	count = 0;
	while (num)
	{
		++count;
		num /= 10;
	}
	return (count);
}

static size_t	ret_count(int n, size_t	count)
{
	if (n < 0)
		return (count + 2);
	else
		return (count + 1);
}

static long	ret_nb(int n)
{
	if (n < 0)
		return (-(long)n);
	else
		return ((long)n);
}

static char	ret_char(int n, long nb)
{
	if (n < 0)
		return ('-');
	else
		return (nb % 10 + '0');
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	count;
	char	*str;

	nb = (long)n;
	count = ft_num_digit_count(nb);
	count = ret_count(n, count);
	if (n == 0)
		++count;
	str = (char *)malloc((count) * sizeof(char));
	if (str == NULL)
		return (NULL);
	nb = ret_nb(n);
	str[count - 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (count - 1)
	{
		str[count - 2] = nb % 10 + '0';
		str[0] = ret_char(n, nb);
		nb /= 10;
		--count;
	}
	return (str);
}
