/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecstrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:59:40 by hohayrap          #+#    #+#             */
/*   Updated: 2021/07/27 23:32:56 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_vecstrdel(char ***vecstrptr)
{
	int index; 

	if (!vecstrptr || !*vecstrptr)
		return ;
	index = -1;
	while ((*vecstrptr)[++index])
		ft_strdel(*vecstrptr + index );
	free(*vecstrptr);
	*vecstrptr = NULL;
}
