/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:05:04 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/30 18:05:05 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_H
# define FUNCTIONAL_H

#include "shell_structures.h"

t_command_side_function		ft_side_funcs_default_constructor(void);
t_command_side_function		ft_scon(t_side_commands name, t_cmd_func cmd);
t_command_function			func_condef(void);
t_command_function			func_con(t_builtin_commands name, t_cmd_func cmd);
t_cmd_func                  ft_search_front_func(t_dict *lcmd);
t_cmd_func					ft_search_side_func(t_dict *lcmd);
t_cmd_func					ft_search_builtin_func(t_dict *lcmd);


int							\
system_command(char **command, t_dict *command_list, char **envp_my, int count);
int                         \
ft_write_file(struct s_dict *dict, char **envp, char **data, int count);
int							\
ft_cd(t_dict *dict, char **envp, char **data, int count);
int							\
ft_pwd(t_dict *dict, char **envp, char **data, int count);
int							\
ft_read_file(t_dict *dcit, char **envp, char **data, int count);
int							\
ft_dwrite_file(t_dict *dict, char **envp, char **data, int count);
int							\
ft_write_bu(t_dict *dict, char **envp, char **data, int count);
int							\
ft_read_bu(t_dict *dict, char **envp, char **data, int count);
int							\
ft_dwrite_bu(t_dict *dict, char **envp, char **data, int count);
int							\
ft_dread_bu(t_dict *dict, char **envp, char **data, int count);
void						ft_dwrite_child(char *check, int *p, t_dict *dict);
void						ft_dwrite_parent(int id, int *p);
int							ft_dread_file(struct s_dict *dict, \
char **envp, char **data, int count);
int							\
ft_exit(t_dict *dict, char **envp, char **data, int count);
int							\
ft_unset(struct	s_dict *dictioanry, char **envp, char **data, int count);
int							\
ft_export(t_dict *dictioanry, char **envp, char **data, int count);
int							\
exec_echo(char **arguments, t_dict *comand_shablon, int count, char **envp_my);
int							\
ft_external(t_dict *dic, char **env, char **data, int count);
int							\
ft_print_echo(t_dict *command_shablon, char **envp_my, char **data, int count);
void						ft_dbu_child(char *check);

#endif