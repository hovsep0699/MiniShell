/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:21:34 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:11:51 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_panic(char *error)
{
	write (2, error, ft_strlen(error));
	write (2, "\n", 1);
	exit (1);
}

void	ft_panic_shell(char *error, char *current)
{
	if (error)
		write (2, error, ft_strlen(error));
	if (current)
		write (2, current, ft_strlen(current));
	write(2, "\n", 1);
}
