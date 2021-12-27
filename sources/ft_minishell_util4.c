/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_util4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:46:03 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 14:11:56 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_index(char *dict, int i)
{printf("\nset =  %s\n",dict);
	if (dict[i] == '-')
		++i;
	printf("\nset =  %i\n",i);
	while (dict[i] && ft_isdigit(dict[i]))
		++i;
		printf("\nset2 =  %i\n",i);
	return (i);
}

t_eqstr	ft_eqdef(char *s1, char *pars_str)
{
	t_eqstr	equ;

	equ.i = 0;
	equ.count = 0;
	equ.subjoin = NULL;
	equ.quate_exist = 1;
	equ.dquate_exist = 1;
	equ.end_index = ft_zero_byte_strlen(s1);
	equ.count = ft_count_quote(pars_str);
	return (equ);
}

void	ft_exitcod(t_eqstr *equ)
{
	char	*tmp_str;

	tmp_str = ft_itoa(g_signal.exit_status);
	equ->len_key = ft_zero_byte_strlen(tmp_str);
	equ->subjoin = ft_realloc_strjoin(equ->subjoin, tmp_str);
	equ->end_index += equ->len_key;
	ft_strdel(&tmp_str);
	equ->i += 2;
}

void	ft_join_util(char *pars_str, t_eqstr *equ)
{
	equ->i++;
	equ->subjoin[equ->end_index++] = pars_str[equ->i];
	equ->i++;
}

void	ft_exp_exist(t_eqstr *equ)
{
	equ->subjoin = ft_realloc_strjoin(equ->subjoin, getenv("HOME"));
	equ->end_index = ft_zero_byte_strlen(equ->subjoin);
	equ->i++;
}
