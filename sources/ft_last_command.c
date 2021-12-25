/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:45:35 by vgaspary          #+#    #+#             */
/*   Updated: 2021/11/07 12:28:31 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_dict	ft_dict_constructor2(void)
{
	t_dict	lcmd;

	lcmd.icom = 0;
	lcmd.last_command = 0;
	lcmd.nerar_exeption = 0;
	lcmd.quote_staet_new = 0;
	lcmd.start_program = 0;
	lcmd.type_command = UNDEFINED;
	lcmd.util_commant = NONE;
	lcmd.variable_dic = NULL;
	lcmd.data = NULL;
	lcmd.line = NULL;
	lcmd.output_data = NULL;
	lcmd.name_file = NULL;
	lcmd.fname_file = NULL;
	lcmd.change_fd_in = -1;
	lcmd.change_fd_out = -1;
	lcmd.echo_option = 0;
	lcmd.isparrent = 1;
	lcmd.is_parent = true;
	return (lcmd);
}

t_dict	ft_dict_constructor(void)
{
	t_dict	lcmd;

	lcmd = ft_dict_constructor2();
	lcmd.fd[0] = dup(STDIN_FILE);
	lcmd.fd[1] = dup(STDIN_FILE);
	lcmd.functions[0] = (t_command_function){ECHO, ft_print_echo};
	lcmd.functions[1] = (t_command_function){EXPORT, ft_export};
	lcmd.functions[2] = (t_command_function){UNSET, ft_unset};
	lcmd.functions[3] = (t_command_function){EXIT, ft_exit};
	lcmd.functions[4] = (t_command_function){ENV, ft_put_env_export};
	lcmd.functions[5] = (t_command_function){CD, ft_cd};
	lcmd.functions[6] = (t_command_function){PWD, ft_pwd};
	lcmd.functions[7] = (t_command_function){WWRITE, ft_write_bu};
	lcmd.functions[8] = (t_command_function){DDWRITE, ft_dwrite_bu};
	lcmd.functions[9] = (t_command_function){UNDEFINED, ft_external};
	lcmd.front_function[0] = (t_front_function){FFREAD, ft_read_bu};
	lcmd.front_function[1] = (t_front_function){FDREAD, ft_dread_bu};
	lcmd.side_functions[0] = (t_command_side_function){WRITE, ft_write_file};
	lcmd.side_functions[1] = (t_command_side_function){READ, ft_read_file};
	lcmd.side_functions[2]
		= (t_command_side_function){DWRITE, ft_dwrite_file};
	lcmd.side_functions[3] = (t_command_side_function){DREAD, ft_dread_file};
	lcmd.side_functions[4] = (t_command_side_function){PIPE, NULL};
	lcmd.side_functions[5] = (t_command_side_function){NONE, NULL};
	return (lcmd);
}

void	ft_dict_destructor(t_dict *lcmd)
{
	ft_strdel(&lcmd->data);
	ft_strdel(&lcmd->output_data);
	ft_strdel(&lcmd->name_file);
	ft_strdel(&lcmd->fname_file);
	ft_dictionary_destructor(lcmd->variable_dic);
}
