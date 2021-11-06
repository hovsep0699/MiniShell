/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:09:39 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/04 22:00:16 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Vache.h"

int	quote_check_sp(int exp_state, int exp_state2, char s, char qu)
{
	if ((s == qu && exp_state2 == 1) && exp_state == 1)
		exp_state = 0;
	else if ((s == qu && exp_state2 == 1) && exp_state == 0)
		exp_state = 1;
	return (exp_state);
}

t_split_next	def(void)
{
	t_split_next	lt;

	lt.i = 0;
	lt.length = 0;
	lt.start = 0;
	lt.exs = 1;
	lt.exs2 = 1;
	return (lt);
}
