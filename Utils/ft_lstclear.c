/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:55:36 by vgaspary          #+#    #+#             */
/*   Updated: 2021/01/31 19:18:26 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Vache.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *t;

	t = NULL;
	while (lst && *lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
}
