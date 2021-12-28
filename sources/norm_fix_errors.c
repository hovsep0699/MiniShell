#include "minishell.h"

void	create_norm_fix_func(char **arg, t_dict *dict, int count, char **envp)
{
	t_cmd_func	cmd;

	cmd = ft_search_front_func(dict);
	cmd(dict, envp, arg, count);
}

void	create_exit_norm_error(int errnum, char **data, t_dict *dict)
{
    if (errnum < 2)
	{
		ft_vecstrdel(&data);
		ft_dict_destructor(dict);
		while (ft_range(g_signal.exit_status, 0, 255))
		{
			if (g_signal.exit_status < 0)
				g_signal.exit_status += 256;
			else
				g_signal.exit_status -= 256;
		}
		exit (g_signal.exit_status);
	}
	g_signal.exit_status = 1;
}

int			create_cd_norm_error(t_dict *dict)
{
    DIR				*current_directory;
	struct dirent	*dp;

	if (dict->data[0] == '-' && ft_ret_end(dict) == 0)
		return (1);
	dict->data = ft_strtrim(dict->data, " ");
	dict->data = ft_realloc_strjoin(dict->data, "/");
    current_directory = opendir(dict->data);
	if (!current_directory)
	{
		g_signal.exit_status = 1;
		ft_putendl_fd("sh: cd: No such file or directory", 2);
		return (1);
	}
	dp = readdir(current_directory);
	if (!dp)
	{
		g_signal.exit_status = 1;
		ft_putendl_fd("sh: cd: No such file or directory", 2);
		return (1);
	}
    return (0);
}

void	create_dict_init_norm_error(t_dict *lcmd)
{
	lcmd->functions[0] = (t_command_function){ECHO, ft_print_echo};
	lcmd->functions[1] = (t_command_function){EXPORT, ft_export};
	lcmd->functions[2] = (t_command_function){UNSET, ft_unset};
	lcmd->functions[3] = (t_command_function){EXIT, ft_exit};
	lcmd->functions[4] = (t_command_function){ENV, ft_put_env_export};
	lcmd->functions[5] = (t_command_function){CD, ft_cd};
	lcmd->functions[6] = (t_command_function){PWD, ft_pwd};
	lcmd->functions[7] = (t_command_function){WWRITE, ft_write_bu};
	lcmd->functions[8] = (t_command_function){DDWRITE, ft_dwrite_bu};
	lcmd->functions[9] = (t_command_function){UNDEFINED, ft_external};
}