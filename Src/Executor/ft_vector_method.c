/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_method.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:03:31 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:40 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	ft_tabcpy_util(int *tab1, int *tab2, size_t size)
{
	size_t	i;

	if (!tab1 || !tab2)
		return ;
	i = 0;
	while (i < size)
	{
		tab1[i] = tab2[i];
		i++;
	}
}

void	ft_init_arrey(t_vector *tab, size_t size)
{
	if (!tab)
		return ;
	tab->arr = NULL;
	tab->size = size;
	tab->capacity = size;
	if (size)
	{
		tab->arr = (int *)malloc(sizeof(int) * size);
		ft_memset(tab->arr, 0, (sizeof(int)));
		if (!tab->arr)
			return ;
	}
}

static void	ft_update_capacity_arrey(t_vector *tab)
{
	int		*new_tab;
	size_t	new_cap;

	if (!tab)
		return ;
	new_cap = tab->capacity;
	if (!new_cap)
		new_cap = 1;
	else if (tab->size >= new_cap)
		new_cap *= 2;
	if (new_cap != tab->capacity)
	{
		new_tab = (int *)malloc(sizeof(int) * new_cap);
		ft_tabcpy_util(new_tab, tab->arr, tab->size);
		if (tab->arr)
			free(tab->arr);
		tab->arr = new_tab;
		tab->capacity = new_cap;
	}
}

void	ft_push_arrey(t_vector *tab, int val)
{
	int	last;

	if (!tab)
		return ;
	ft_update_capacity_arrey(tab);
	last = 0;
	if (tab->size)
		last = tab->arr[tab->size - 1];
	tab->arr[tab->size] = val;
	tab->size++;
	if (tab->size && val == last)
		--tab->size;
}
