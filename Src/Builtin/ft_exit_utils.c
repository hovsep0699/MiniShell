/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:37:06 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:13:52 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_ismultiply_overflow_u(long a, long b)
{
	if (a == 0 || b == 0)
		return (0);
	if (a > LONG_MAX / b || a < LONG_MIN / b)
		return (1);
	return (0);
}

int	ft_isadd_overflow_u(long a, long b)
{
	if (a > 0 && b > 0 && a > LONG_MAX - b)
		return (1);
	if (a < 0 && b < 0 && a < LONG_MIN - b)
		return (1);
	return (0);
}

size_t	ft_atoll_util(size_t i, char *str, int *is_overflowed)
{
	size_t	res;
	size_t	tmp;

	res = 0;
	while (ft_isdigit(str[i]))
	{
		if (ft_ismultiply_overflow_u(res, 10))
			*is_overflowed = 1;
		tmp = res * 10;
		if (ft_isadd_overflow_u(tmp, str[i] - '0'))
			*is_overflowed = 1;
		res = tmp + (str[i] - '0');
		++i;
	}
	return (res);
}

long long	ft_atoll(char *str, int *is_overflowed)
{
	size_t	i;
	long	sign;
	size_t	res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	res = ft_atoll_util(i, str, is_overflowed);
	return (sign * res);
}
