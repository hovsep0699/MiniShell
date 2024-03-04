/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:04:43 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/27 18:14:19 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_function_entity	*ft_entity_to_function(t_hash_entity	*hash)
{
	return ((t_function_entity *)hash);
}

t_env_entity	*ft_entity_to_env(t_hash_entity *hash)
{
	return ((t_env_entity *)hash);
}

t_hash_entity	*ft_function_to_entity(t_function_entity *func)
{
	return ((t_hash_entity *)func);
}

t_hash_entity	*ft_env_to_entity(t_env_entity *env)
{
	return ((t_hash_entity *)env);
}
