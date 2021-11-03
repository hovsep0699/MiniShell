/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_util5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:36:25 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/02 20:14:38 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exp_util(t_eqstr *equ, t_dict *dict, char *pars_str)
{
	equ->subjoin = ft_realloc_strjoin(equ->subjoin,
			find_data((pars_str + equ->i + 1), dict->variable_dic));
	equ->end_index += ft_zero_byte_strlen(equ->subjoin) - equ->end_index;
	ft_isalnum_str(pars_str + equ->i + 1, &equ->i);
	equ->i += 2;
}

int	ft_dis_strchr(const char *s, int c)
{
	int	t;

	t = 0;
	while (s[t])
	{
		if (s[t] == c)
			return (t);
		t++;
	}
	if (s[t] == '\0' && !c)
		return (t);
	return (0);
}

char	*ft_strnull(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (0 + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

void	ft_join_util2(char *pstr, t_eqstr	*equ, t_dict *dict)
{
	if (ft_count_quote_character(pstr[equ->i],
			&equ->quate_exist, &equ->dquate_exist))
		equ->i++;
	else if (pstr[equ->i] == '\\'
		&& (equ->dquate_exist != 0 && equ->quate_exist != 0))
		ft_join_util(pstr, equ);
	else if (pstr[equ->i] == '$'
		&& pstr[equ->i + 1] == '?' && equ->quate_exist != 0)
		ft_exitcod(equ);
	else if (pstr[equ->i] == '$' && equ->quate_exist != 0)
		ft_exp_util(equ, dict, pstr);
	else if (pstr[equ->i] == '~' && equ->dquate_exist != 0
		&& equ->quate_exist != 0
		&& equ->i == 0 && (pstr[equ->i + 1] == '\0' || pstr[equ->i + 1] == '/'))
		ft_exp_exist(equ);
	else
		equ->subjoin[equ->end_index++] = pstr[equ->i++];
}

int	ft_isnull(t_dict	*lcmd)
{
	if (lcmd->line == NULL)
	{
		ft_putstr_fd("\033[1AMinishell$> exit\n", 2);
		exit(0);
	}
	if (lcmd->line[0] == 0)
		return (1);
	return (0);
}
