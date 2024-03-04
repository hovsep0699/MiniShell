/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_methods.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:36:23 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:21 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_histmv_util(t_history *h1, t_history *h2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		h1->lines[i] = ft_strdup(h2->lines[i]);
		i++;
	}
}

void	ft_init_history(t_history *hist, size_t size)
{
	if (!hist)
		return ;
	hist->lines = NULL;
	hist->size = size;
	hist->capacity = size;
	if (size)
	{
		hist->lines = (char **)malloc(sizeof(char *) * size);
		ft_memset(hist->lines, 0, (sizeof(char *)));
		if (!hist->lines)
			return ;
	}
}

static void	ft_update_capacity_hist(t_history *hist)
{
	t_history	new_hist;
	size_t		new_cap;

	if (!hist)
		return ;
	new_cap = hist->capacity;
	if (!new_cap)
		new_cap = 1;
	else if (hist->size >= new_cap)
		new_cap *= 2;
	if (new_cap != hist->capacity)
	{
		new_hist.lines = (char **)malloc(sizeof(char *) * new_cap);
		ft_histmv_util(&new_hist, hist, hist->size);
		ft_history_cleanup(hist);
		hist->lines = new_hist.lines;
		hist->capacity = new_cap;
	}
}

void	ft_push_history(t_history *hist, char *val)
{
	if (!hist || !val)
		return ;
	ft_update_capacity_hist(hist);
	hist->lines[hist->size] = ft_strdup(val);
	hist->size++;
}
