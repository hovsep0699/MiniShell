/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_isnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:28:26 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 19:30:53 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring.h>

bool	ft_isnum_str(char *str)
{
	int	index;

	if (!str)
		return (false);
	index = -1;
	while (str[++index])
		if (!ft_isdigit(str[index]))
			return (false);
	return (true);
}
