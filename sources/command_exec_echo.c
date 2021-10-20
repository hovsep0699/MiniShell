#include "minishell.h"

int ft_print_echo(t_last_command *command_shablon, char **envp, char **data,int count)
{
	write(1, command_shablon->data, ft_zero_byte_strlen(command_shablon->data));
	if(command_shablon->echo_option != 1)
			write(1,"\n",1);
	g_signal.exit_status = 0;
		return(g_signal.exit_status);
}

int	ft_exit(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
	int exit_status;
	int index;
	bool is_error;

	index = 0;
	is_error = false;
	if (!command_shablon->data)
		g_signal.exit_status = 0;
	else
	{
		while (command_shablon->data[index] && ft_isspace(command_shablon->data[index])) ++index;
		if (!command_shablon->data[index])
			is_error = true;
		else
		{
			while (command_shablon->data[index] && ft_isdigit(command_shablon->data[index])) ++index;
			--index;
			if (!command_shablon->data[index] || (!ft_isdigit(command_shablon->data[index]) && !ft_isspace(command_shablon->data[index])))
			{
				ft_putstr("exit\n");
				is_error = true;
			}
			else
				while (command_shablon->data[++index] && ft_isspace(command_shablon->data[index])) ;

		}
		if (command_shablon->data[index] && !is_error)
			is_error = true;
		if (is_error)
		{
			ft_putstr_fd("minishell: exit:",2);
			ft_putstr_fd(command_shablon->data,2);
			ft_putstr_fd("numeric argument required\n",2);
			g_signal.exit_status = COMMAND_NOT_FOUND;
		}
		else
			g_signal.exit_status = ft_atoi(command_shablon->data);
	}
	ft_vecstrdel(&data);
	ft_last_command_destructor(command_shablon);
	exit(g_signal.exit_status);
}

int	ft_cd(t_last_command *command_shablon, char **envp, char **data, int count)
{
	int err;
	int end;
	char new_path[PATH_MAX];

	if (!command_shablon->data)
		return 0;
	err = chdir(command_shablon->data);
	
	if (err == -1)
	{
		printf("%s\n", strerror(errno));
		return errno;
	}
	getcwd(new_path, PATH_MAX);
	change_item(find_data("PWD",command_shablon->variable_dic),find_data_int("OLDPWD=",command_shablon->variable_dic),command_shablon->variable_dic);
	change_item(new_path, find_data_int("PWD=",command_shablon->variable_dic),command_shablon->variable_dic);
	g_signal.exit_status = 0;
	return(g_signal.exit_status);
}

int	ft_pwd(t_last_command *command_shablon, char **envp_my, char **data, int count)
{
	ft_putstr_fd(find_data("PWD",command_shablon->variable_dic),1);
	ft_putchar('\n');
	return 0;
}