/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:30:20 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 13:00:53 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "shell_structures.h"
# include "functional.h"
# include "dictionary.h"
# include "shell_signals.h"

size_t						\
ft_joins(char const *s2, size_t i, int count, char *subjoin);
int							ft_dis_strchr(const char *s, int c);
char						*ft_clean(char *bf, int length);
char						*ft_single_join(void);
char						*ft_strnull(void);
int							ft_strcmp_char(char *str, char c, int count);
int							ft_flag_find(char str);
char						*enter_split_sapce(char **not_splite);
void						ft_print_welcome(char *path);
char						\
*ft_strjoin_minishell(char *s1, int start_index, int end_index, int isflag);
int							free_space(char *clean_space);
int							\
ft_alloc_split_minishell(char const *s, char c, char exp, char exp2);
char						*ft_tolower_minishell(char *upper_str, int *len);
char						\
*ft_equal_strjoin(char *s1, t_dict *dict, char *pars_str, int end_of_line);
int							find_equal_part(char *str);
int							ft_count_quote(char *s);
void						ft_char_pointer_erase(char *str, size_t it);
int							ft_isalnum_str(char *str, int *i);
int							\
ft_count_quote_character(char ch, int *q, int *dq);
int							\
ft_qch(int state, int state2, char now_character, char quote);
int							ft_find_element(char *str);
size_t						\
ft_joins_dict(char const *s2, size_t i, int count, char *subjoin);
int							ft_set_index(char *dict, int i);
void						ft_join_util(char *pars_str, t_eqstr *equ);
void						ft_exp_exist(t_eqstr *equ);
void						\
ft_exp_util(t_eqstr *equ, t_dict *dict, char *pars_str);
int							ft_dis_strchr(const char *s, int c);
char						*ft_strnull(void);
void						\
ft_join_util2(char *pstr, t_eqstr *equ, t_dict *dict, int mod);
int							ft_isnull(char	*line, int mod);
char						**av_ret(char *tmp_path, char **data_sp);
int							ft_iszero(int end, int count);
int							export_check(char *str, int len);
int							ft_ich(char ch);
int							runfileutil_bu(char **argum, t_dict *dict, int i);
char						*ft_here_strjoin(char *s1, t_dict *dict);
void                        ft_def_flag(t_dict *dict);

#endif
