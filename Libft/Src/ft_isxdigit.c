/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:43:06 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:05 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isxdigit(int num)
{
	if ((num >= '0' && num <= '9') || (num >= 'A' && num <= 'F') \
		|| (num >= 'a' && num <= 'f'))
		return (1);
	else
		return (0);
}