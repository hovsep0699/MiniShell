/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 00:16:35 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:46 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_number(const char *str, int sign)
{
	int number;

	number = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		++str;
	}
	number *= sign;
	return (number);
}

static int	ft_atoi_is_spaces(const char c)
{
	return (c == '\t' || c == '\n' ||
c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

int			ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (ft_atoi_is_spaces(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		++str;
	}
	return (ft_atoi_number(str, sign));
}
