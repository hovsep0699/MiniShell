/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstdlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:22:57 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/28 20:23:00 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTDLIB_H
# define CSTDLIB_H

# include <stdlib.h>
# include <unistd.h>

/*
# define FT_MAX(x,y)(x > y ? x : y)
# define FT_MIN(x,y)(x < y ? x : y)
*/

void	*ft_realloc(void *ptr, size_t newsize);

void	*ft_memalloc(size_t size);

void	*ft_calloc(size_t count, size_t size);

void	ft_memdel(void **mem);

#endif
