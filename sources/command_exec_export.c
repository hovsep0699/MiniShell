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
	dictionary_t	*tmp;
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
		end_index = ft_dict_init(dict, end_index, str[end_index])
			ft_vecstrdel(&str);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int	ft_unset(t_dict *dictioanry, char **envp, char **data, int count)
{
	t_unset	unset_var;

	unset_var.i = 0;
	unset_var.len = ft_zero_byte_strlen(dictioanry->data);
	unset_var.dict_key_len = 0;
	unset_var.endindex = 0;
	unset_var.contindex = 0;
	unset_var.provide = NULL;
	unset_var.tmp = dictioanry->variable_dic;
	while (dictioanry->data[unset_var.contindex])
	{
		unset_var.endindex = (unset_var.endindex = ft_strcmp_char(dictioanry->data + unset_var.contindex,' ', unset_var.len)) > 0 ? unset_var.endindex : unset_var.len;
    	while (unset_var.tmp != NULL)
    	{
        	unset_var.dict_key_len = ft_zero_byte_strlen(tmp->key);
        	if(ft_strncmp(dictioanry->data + unset_var.contindex,tmp->key,unset_var.endindex) == 0 && unset_var.endindex - unset_var.contindex == unset_var.dict_key_len)
			{
				if(dictioanry->variable_dic == unset_var.tmp)
				dictioanry->variable_dic = dictioanry->variable_dic->next;
				if(provide != NULL)
					unset_var.provide->next = tmp->next;
				else
					unset_var.provide = tmp->next;
				ft_dictionary_del_key(unset_var.tmp);
				break;
			}
			unset_var.provide = unset_var.tmp;
			unset_var.tmp = tmp->next;
		}
		unset_var.tmp = dictioanry->variable_dic;
		if (unset_var.len <= unset_var.endindex)
			break;
		unset_var.contindex = unset_var.endindex + 1;
	}
	g_signal.exit_status = 0;
	return (g_signal.exit_status);  
}
