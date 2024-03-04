/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:03:29 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:12:18 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfind(const char *str, const char *chars)
{
	const char		*result;

	if (!str || !chars)
		return (0);
	result = ft_strpbrk(str, chars);
	if (result != NULL)
		return ((int)(result - str));
	return (-1);
}
