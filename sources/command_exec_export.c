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
	dictionary_t	*tmp;

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
	str = ft_split_Vache(dict->data, ' ', '\'', '\"');
	start_index = ft_vecstrlen(str);
	end_index = 0;
	while (end_index < start_index)
		end_index = ft_dict_init(dict, end_index, str[end_index]);
	ft_vecstrdel(&str);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}
t_unset ft_unset_construct(t_dict *dictioanry)
{
	t_unset unset_var;

	unset_var.i = 0;
	unset_var.len = ft_zero_byte_strlen(dictioanry->data);
	unset_var.dict_key_len = 0;
	unset_var.endindex = 0;
	unset_var.contindex = 0;
	unset_var.provide = NULL;
	unset_var.tmp = dictioanry->variable_dic;
	unset_var.end_inde_n = 0;
	return (unset_var);
}
void ft_del(t_dict *dic,t_unset *unvar)
{
	if(unvar->end_inde_n == unvar->len)
		unvar->endindex = unvar->len;
	else
		unvar->endindex += unvar->end_inde_n;
    while (unvar->tmp != NULL)
    {
		unvar->dict_key_len = ft_zero_byte_strlen(unvar->tmp->key);
        if(ft_strncmp(dic->data + unvar->contindex,unvar->tmp->key,unvar->end_inde_n) == 0 && unvar->endindex - unvar->contindex == unvar->dict_key_len)
		{
			if(dic->variable_dic == unvar->tmp)
				dic->variable_dic = dic->variable_dic->next;
			if(unvar->provide != NULL)
				unvar->provide->next = unvar->tmp->next;
			else
				unvar->provide = unvar->tmp->next;
			ft_dictionary_del_key(unvar->tmp);
			break;
		}
	unvar->provide = unvar->tmp;
	unvar->tmp = unvar->tmp->next;
	}
}

int	ft_unset(t_dict *dic, char **envp, char **data, int count)
{
	t_unset	unvar;

	unvar = ft_unset_construct(dic);
	while (dic->data[unvar.contindex])
	{
		if(ft_strcmp_char(dic->data + unvar.contindex,' ', unvar.len) > 0)
			unvar.end_inde_n = ft_strcmp_char(dic->data + unvar.contindex,' ', unvar.len);
		else
			unvar.end_inde_n = unvar.len;
    	ft_del(dic,&unvar);
		unvar.tmp = dic->variable_dic;
		if (unvar.len <= unvar.endindex)
			break;
		unvar.contindex = unvar.endindex + 1;
		unvar.endindex++;
	}
	g_signal.exit_status = 0;
	return (g_signal.exit_status);  
}
