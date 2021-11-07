/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:22:04 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/28 20:22:07 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTACK_H
# define CSTACK_H

# include "clist.h"

typedef struct stack	t_stack;

struct s_stack
{
	t_list	data;
	int		size;
	t_node	*(*top)(t_stack st);
	void	(*push)(t_stack *st, void *data, int size);
	t_node	*(*pop)(t_stack *st);

};

#endif
