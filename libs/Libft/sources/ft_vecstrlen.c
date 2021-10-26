/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:05:25 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/26 21:05:27 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstring.h"

size_t	ft_vecstrlen(char **vecstr)
{
	size_t	count;

	count = 0;
	while (vecstr[count])
		++count;
	return (count);
}
