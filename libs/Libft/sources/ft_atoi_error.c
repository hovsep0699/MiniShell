/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:08:57 by hohayrap          #+#    #+#             */
/*   Updated: 2021/06/24 23:18:48 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		starting_point(const char *str)
{
	int index;

	index = 0;
	while (str[index] == '\n' || str[index] == '\t' || str[index] == '\f' || \
			str[index] == '\v' || str[index] == '\r' || str[index] == ' ')
		++index;
	return (index);
}

static	int		check_sign(const char *str, int *index, int *sign)
{
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			*sign = -1;
		++(*index);
	}
	return (str[*index]);
}

int				ft_atoi_error(const char *str)
{
	long	res;
	int		sign;
	int		index;

	res = 0;
	sign = 1;
	index = starting_point(str);
	if (!check_sign(str, &index, &sign))
		return (0);
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			res = res * 10 + str[index] - '0';
		else if (str[index] == ',')
			break ;
		else
			return (0);
		++index;
	}
	res = sign * res;
	return (res <= 2147483647 && res >= -2147483648);
}
