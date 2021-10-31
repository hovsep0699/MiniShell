/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrpint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 22:23:34 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/31 20:58:43 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring.h>

void	ft_vecstrprint(char **vecstr)
{
	int	index;

	if (!vecstr || !*vecstr)
		return ;
	index = -1;
	while (vecstr[++index])
	{
		ft_putstr(vecstr[index]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
}
