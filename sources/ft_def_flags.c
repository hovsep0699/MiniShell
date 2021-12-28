/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:01:27 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/28 22:02:52 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_def_flag(t_dict *dict)
{
	dict->type_command = UNDEFINED;
	dict->fr_command = FNONE;
	dict->util_commant = NONE;
}

int	back_space_exist(char *pstr, t_eqstr *equ)
{
	int	exist;

	exist = 1;
	if (equ->i != 0 && pstr[equ->i - 1] == '\\')
	{
		if (equ->i > 1 && pstr[equ->i - 2] == '\\')
			exist = 0;
		else
			exist = 1;
	}
	else
		exist = 0;
	return (exist);
}
