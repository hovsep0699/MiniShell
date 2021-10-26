/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:55:07 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 20:56:55 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clist.h"

void	ft_swap(void *a, void *b, size_t len)
{
	unsigned char	*first;
	unsigned char	*second;
	unsigned char	tmp;
	size_t			index;

	first = a;
	second = b;
	index = -1;
	while (++index != len)
	{
		tmp = first[index];
		first[index] = second[index];
		second[index] = tmp;
	}
}
