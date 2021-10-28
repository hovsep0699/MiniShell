/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:39:30 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/21 21:51:53 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_put_env_export(t_dict *dictionary, char **envp, char **data, int count)
{
	int				i;
	t_dictionary	*tmp;

	i = 0;
	tmp = dictionary->variable_dic;
	while (tmp != NULL)
	{
		ft_putstr_fd(tmp->key, 1);
		ft_putstr_fd("=", 1);
		if (tmp->item != NULL && tmp->item[0] != '\0')
			ft_putstr_fd(tmp->item, 1);
		else
			ft_putstr_fd("", 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_export(t_dict *dict, char **envp, char **data, int count)
{
	char			**str;
	int				start_index;
	int				end_index;

	if (ft_zero_byte_strlen(dict->data) == 0)
	{
		ft_put_env_export(dict, envp, data, count);
		return (SUCCESS);
	}
	str = ft_split_vache(dict->data, ' ');
	start_index = ft_vecstrlen(str);
	end_index = 0;
	while (end_index < start_index)
		end_index = ft_dict_init(dict, end_index, str[end_index]);
	ft_vecstrdel(&str);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

t_unset	ft_unset_construct(t_dict *dictioanry)
{
	t_unset	unset_var;

	unset_var.i = 0;
	unset_var.len = ft_zero_byte_strlen(dictioanry->data);
	unset_var.dklen = 0;
	unset_var.eind = 0;
	unset_var.cind = 0;
	unset_var.provide = NULL;
	unset_var.tmp = dictioanry->variable_dic;
	unset_var.esp = 0;
	return (unset_var);
}

void	ft_del(t_dict *dic, t_unset *unvar)
{
	if (unvar->esp == unvar->len)
		unvar->eind = unvar->len;
	else
		unvar->eind += unvar->esp;
	while (unvar->tmp != NULL)
	{
		unvar->dklen = ft_zero_byte_strlen(unvar->tmp->key);
		if (ft_strncmp(dic->data + unvar->cind,
				unvar->tmp->key, unvar->esp) == 0
			&& unvar->eind - unvar->cind == unvar->dklen)
		{
			if (dic->variable_dic == unvar->tmp)
				dic->variable_dic = dic->variable_dic->next;
			if (unvar->provide != NULL)
				unvar->provide->next = unvar->tmp->next;
			else
				unvar->provide = unvar->tmp->next;
			ft_dictionary_del_key(unvar->tmp);
			break ;
		}
		unvar->provide = unvar->tmp;
		unvar->tmp = unvar->tmp->next;
	}
}

int	ft_unset(t_dict *dic, char **envp, char **data, int count)
{
	t_unset	unvar;

	unvar = ft_unset_construct(dic);
	while (dic->data[unvar.cind])
	{
		if (ft_strcmp_char(dic->data + unvar.cind, ' ', unvar.len) > 0)
			unvar.esp = ft_strcmp_char(dic->data + unvar.cind, ' ', unvar.len);
		else
			unvar.esp = unvar.len;
		ft_del(dic, &unvar);
		unvar.tmp = dic->variable_dic;
		if (unvar.len <= unvar.eind)
			break ;
		unvar.cind = unvar.eind + 1;
		unvar.eind++;
	}
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}
