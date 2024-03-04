/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sematic_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:31 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:09:54 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMATIC_STRUCT_H
# define SEMATIC_STRUCT_H

typedef enum e_status_codes	t_status_codes;

typedef t_status_codes		(*t_callback)(t_ast_node*);

enum e_status_codes
{
	SUCCESS_CODE		= 0,
	UNEXPECTED_PIPE		= 1L << 0,
	UNEXPECTED_REDIRECT = 1L << 1,
	EMPTY_SUBSHELL		= 1L << 2,
	MISSING_OPERATOR	= 1L << 3,
	MISSING_TOKEN		= 1L << 4
};

#endif