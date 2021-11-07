/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:19:01 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/28 20:19:31 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIST_H
# define CLIST_H

# include <stdlib.h>
# include <unistd.h>
# include "cstring.h"

typedef struct s_list	t_list;

typedef struct s_node	t_node;

struct s_node
{
	void		*data;
	t_node		*next;
	t_node		*previous;
	int			size;
	void		(*insert_before)(t_node *self, t_node *node);
	void		(*insert_after)(t_node *self, t_node *node);
	void		(*swap)(t_node *self, t_node *node);
	void		(*reverse)(t_node *self);
	void		(*disconnect)(t_node *node);
};

struct		s_list
{
	t_node		*begin;
	t_node		*end;
	int			size;
	void		(*push_back)(t_list *lst, void *data, int size);
	void		(*push_front)(t_list *lst, void *data, int size);
	void		(*pop_front)(t_list *lst);
	void		(*pop_back)(t_list *lst);
	t_node		*(*advance)(t_node *it, int dist);
	t_node		*(*erase)(t_list *lst, t_node *it);
	t_node		*(*erase_between)(t_list *lst, t_node *start, t_node *end);	
};

void				ft_node_disconnect(t_node *node);

t_node				*ft_list_iterator_advance(t_node *it, int dist);

int					ft_list_size(t_list *self);

t_list				ft_list_default_constructor(void);

t_list				ft_list_copy_constructor(const t_list *list);

void				ft_swap(void *a, void *b, size_t size);

#endif
