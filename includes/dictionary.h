/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:00:27 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/28 21:09:45 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include "shell_structures.h"

t_dictionary				*ft_dictionarylast(t_dictionary *lst);
t_dictionary				*ft_dictionary_create(char *items);
void						ft_dictionary_del(t_dictionary *del_stack);
t_dict						ft_dict_constructor(void);
void						\
ft_dictionaryadd_back(t_dictionary **lst, t_dictionary *newd);
int							\
ft_dictionarysize(t_dictionary *stack);
int							find_data_int(char *key, t_dictionary *command);
void						\
change_item(char *new_item, int key_index, t_dictionary *dict);
char						*find_data(char *key, t_dictionary *command);
void						\
ft_dictionary_del_key(t_dictionary *del_stack);
void						ft_dictionary_destructor(t_dictionary *dict);
void						ft_dict_destructor(t_dict *lcmd);
int							\
ft_dict_init(t_dict *dict, int end_index, char *str);
void						ft_command_dict(char *lower_case, \
char *upper_case, t_dict *dict, char **list);
int							ft_exit_status(t_dict *dict);
int							runfileutil(char **argum, t_dict *dict, int i);
int							\
ft_execendline(char **arg, t_dict *dict, int count, char **envp_my);
int							\
ft_put_enxport_env(t_dict *dictionary, char **envp, char **data, int count);
int							\
ft_put_env_export(t_dict *dict, char **env, char **data, int count);
t_dictionary				*ft_env_copy(char **env);

#endif