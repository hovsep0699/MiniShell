/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:09:36 by vgaspary          #+#    #+#             */
/*   Updated: 2021/01/31 19:27:59 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft_Vache.h"

t_list	*ft_lstnew(void *content)
{
	t_list *s;

	if (!(s = (t_list *)malloc(sizeof(*s))))
		return (NULL);
	s->content = (void *)content;
	s->next = NULL;
	return (s);
}
