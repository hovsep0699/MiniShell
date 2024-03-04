/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sematic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:08:26 by gehovhan          #+#    #+#             */
/*   Updated: 2024/02/27 18:09:57 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMATIC_H
# define SEMATIC_H

# include "shell.h"

/**
 * Src/Sematic/ft_error_messages.c
 */
char			*ft_get_error_message(t_status_codes code);

/**
 * Src/Sematic/ft_sematic_with_list.c
 */
t_status_codes	ft_sematic_with_list(t_command *cmd);

/**
 * Src/Sematic/ft_sematic_with_tree.c
 */
t_status_codes	ft_callback(t_status_codes code, t_callback callback, \
				t_ast_node *node);
t_status_codes	ft_validate_operator(t_ast_node *node);
t_status_codes	ft_validate_command(t_ast_node *node);
t_status_codes	ft_validate_redirect(t_ast_node *node);
t_status_codes	ft_validate_subshell(t_ast_node *node);
t_status_codes	ft_validate_empty(t_ast_node *node);
t_status_codes	ft_sematic_with_tree(t_ast_node *root);

/**
 * Src/Sematic/ft_sematic.c
 */
t_container		ft_sematic(t_container cont, t_list_token *list);

#endif