/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:24:42 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 21:12:57 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_state(char c, int state)
{
	(void)state;
	if (c == '=')
		return (1);
	return (0);
}

t_split	def_exp(void)
{
	t_split	exp;

	exp.i = 0;
	exp.j = 0;
	exp.state = 0;
	return (exp);
}

int	export_check(char *str, int len)
{
	t_split	exp;

	(void)len;
	exp = def_exp();
	while (str[exp.i])
	{
		if (!(ft_isalnum(str[exp.i]) || str[exp.i] == '_' \
		|| str[exp.i] == '=') && exp.state != 1)
			return (1);
		if (str[exp.i] == '=')
		{
			exp.state = 1;
			exp.i++;
		}
		if (check_state(str[exp.i], exp.state) == 1)
			return (1);
		exp.i++;
	}
	return (0);
}

int	ft_ich(char ch)
{
	int	exist;

	exist = (ft_isalnum(ch) || ch == '_');
	return (exist);
}
