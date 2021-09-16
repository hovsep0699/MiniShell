/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 23:42:34 by hohayrap          #+#    #+#             */
/*   Updated: 2021/03/23 16:14:16 by hohayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *obj;

	if (!(obj = (void *)malloc(count * size)))
		return (NULL);
	ft_memset(obj, 0, count * size);
	return (obj);
}
