/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Vache.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:45:41 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/04 22:01:53 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VACHE_H
# define LIBFT_VACHE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "cstring.h"

# define CHAR_QUATES 39
# define CHAR_DQUATES 34

typedef struct s_form_next_line
{
	int			r;
	char		*bf;
}				t_form_next_line;

typedef struct s_next_lit
{
	size_t	start;
	size_t	length;
	size_t	i;
	int		exs;
	int		exs2;
}				t_split_next;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_strchr_gnl(const char *s, int c);

int				get_next_line(int fd, char **line);

size_t			ft_joins_gnl(char const *s2, size_t i, char *subjoin);

char			*ft_clean(char *bf, int length);

char			*ft_single_join(void);

char			*ft_strnull(void);

char			**ft_split_vache(char const *s, char c);

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_front(t_list **alst, t_list *neww);

void			ft_lstadd_back(t_list **alst, t_list *neww);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void*));

int				quote_check_sp(int exp_state, \
int exp_state2, char s, char quote);

t_split_next	def(void);
#endif
