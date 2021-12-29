/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_fix_errors.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 20:04:24 by vgaspary          #+#    #+#             */
/*   Updated: 2021/12/29 20:53:13 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_FIX_ERRORS_H
# define NORM_FIX_ERRORS_H

# include "shell_structures.h"
# include "functional.h"
# include "dictionary.h"
# include "shell_signals.h"

void						\
create_norm_fix_func(char **arg, t_dict *dict, int count, char **envp);
void						\
create_exit_norm_error(int errnum, char **data, t_dict *dict);
int							create_cd_norm_error(t_dict *dict);
void						\
change_item_dict(char *new_item, int key_index, t_dictionary *dict);
void						create_dict_init_norm_error(t_dict *lcmd);
t_split						def_split(void);
void						ft_signals_print(char *copy);
void						\
ft_clean_dwrite(char *check, char *line, char **chek_str, int p);
void						ft_norm_write_close(int p, char *line);
void						ft_norm_write_close(int p, char *line);
void						\
create_norm_fix_func2(char **arg, t_dict *dict, int count, char **envp);
int							ft_fname_null(struct	s_dict *dict, int fd);
void						external_error_print(char *data);

#endif