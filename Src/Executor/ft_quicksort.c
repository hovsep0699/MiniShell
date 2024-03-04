/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:35:08 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:15:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_partition(char **arr, int low, int high)
{
	int		j;
	int		i;
	char	*pivot;

	j = low;
	i = low - 1;
	pivot = arr[high];
	while (j < high)
	{
		if (ft_strcmp(arr[j], pivot) < 0)
			ft_strswap(&arr[++i], &arr[j]);
		j++;
	}
	ft_strswap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

// Quicksort algorithm
void	ft_quicksort(char **arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = ft_partition(arr, low, high);
		ft_quicksort(arr, low, pi - 1);
		ft_quicksort(arr, pi + 1, high);
	}
}

t_hash_table_arr	ft_sort_env(t_hash_table *table)
{
	t_hash_table_arr	env_arr;

	env_arr = ft_convert_env_to_args(table, EXPORT, 1);
	ft_quicksort(env_arr.table, 0, env_arr.size - 1);
	return (env_arr);
}
