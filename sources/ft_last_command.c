#include "minishell.h"

t_last_command ft_last_command_constructor()
{
    t_last_command lcmd;

    lcmd.index_command = 0;
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
    lcmd.change_fd_in = -1;
    lcmd.change_fd_out = -1;
    lcmd.echo_option = 0;
    lcmd.exit_status = 0;
    lcmd.isparrent = 1;
    lcmd.fd[0] = dup(STDIN_FILE);
    lcmd.fd[1] = dup(STDIN_FILE);
    lcmd.functions[0] = (t_command_function){ECHO, ft_print_echo};
    lcmd.functions[1] = (t_command_function){EXPORT, ft_export};
    lcmd.functions[2] = (t_command_function){UNSET, ft_unset};
    lcmd.functions[3] = (t_command_function){EXIT, ft_exit};
    lcmd.functions[4] = (t_command_function){ENV, ft_put_env_export};
    lcmd.functions[5] = (t_command_function){CD, ft_cd};
    lcmd.functions[6] = (t_command_function){PWD, ft_pwd};
    lcmd.functions[7] = (t_command_function){UNDEFINED, ft_external};
    lcmd.side_functions[0] = (t_command_side_function){WRITE, ft_write_file};
    lcmd.side_functions[1] = (t_command_side_function){READ, ft_read_file};
    lcmd.side_functions[2] = (t_command_side_function){DWRITE, ft_double_write_file};
    lcmd.side_functions[3] = (t_command_side_function){DREAD, ft_dwrite_file};
    lcmd.side_functions[4] = (t_command_side_function){PIPE, NULL};
    lcmd.side_functions[5] = (t_command_side_function){NONE, NULL};
    return lcmd;
}


void    ft_last_command_destructor(t_last_command *lcmd)
{
	ft_strdel(&lcmd->data);
	ft_strdel(&lcmd->output_data);
	ft_strdel(&lcmd->name_file);
	ft_dictionary_destructor(lcmd->variable_dic);
}
