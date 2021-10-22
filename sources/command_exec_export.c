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
	{
		if ((dict->i = find_data_int(str[end_index], dict->variable_dic)) == -1)
		{
			if ((tmp = ft_dictionary_create(str[end_index])) == NULL)
			{
				tmp = NULL;
				end_index++;
				continue;
			}
			ft_dictionaryadd_back(&(dict->variable_dic), tmp);
		}
		else
			change_item(str[end_index],dict->i,dict->variable_dic);
		tmp = NULL;
		end_index++;
	}
	ft_vecstrdel(&str);
	g_signal.exit_status = 0;
	return (g_signal.exit_status);
}

int ft_unset(t_dict * dictioanry, char **envp, char **data, int count)
{
    int i;
    int len;
    int contindex;
    int endindex;
    dictionary_t *tmp;
    dictionary_t *provide;

    i = 0;
    len = ft_zero_byte_strlen(dictioanry->data);
    int dict_key_len = 0;
    endindex = 0;
    contindex = 0;
    provide = NULL;
    tmp = dictioanry->variable_dic; 
    while (dictioanry->data[contindex])
    {
       endindex = (endindex = ft_strcmp_char(dictioanry->data + contindex,' ',len)) > 0 ? endindex : len;
        while (tmp != NULL)
        {
            dict_key_len = ft_zero_byte_strlen(tmp->key);
           if(ft_strncmp(dictioanry->data + contindex,tmp->key,endindex) == 0 && endindex - contindex == dict_key_len)
            {
                if(dictioanry->variable_dic == tmp)
                    dictioanry->variable_dic = dictioanry->variable_dic->next;
                if(provide != NULL)
                    provide->next = tmp->next;
                else
                    provide = tmp->next;
                ft_dictionary_del_key(tmp);
                break;
            }
            provide = tmp;
            tmp = tmp->next;
        }
        tmp = dictioanry->variable_dic;
        if (len <= endindex)
            break;
        contindex = endindex + 1;
    }
    g_signal.exit_status = 0;
    return(g_signal.exit_status);
    
}
