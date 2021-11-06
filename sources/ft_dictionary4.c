/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:24:42 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/06 21:45:37 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_state(char c, int state)
{
	if (c == '=')
		return (1);
	if ((ft_isspace(c) && state == 1) \
	 || !(ft_isalnum(c) || c == '_'))
		 return (1);
	else
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

	exp = def_exp();
	while (str[exp.i])
	{
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

	exist = ft_isalnum(ch) || ch == '_';
	return (exist);
}