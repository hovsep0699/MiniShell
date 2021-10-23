#include "minishell.h"

void	ft_command_dict(char *lower_case, char *upper_case, t_dict *dict)
{
	if (ft_strcmp(lower_case, "echo") == 0)
		dict->type_command = ECHO;
	else if (ft_strcmp(lower_case, "pwd") == 0)
		dict->type_command = PWD;
	else if (ft_strcmp(lower_case, "env") == 0)
		dict->type_command = ENV;
	else if (ft_strcmp(upper_case, "exit") == 0)
		dict->type_command = EXIT;
	else if (ft_strcmp(lower_case, "export") == 0)
		dict->type_command = EXPORT;
	else if (ft_strcmp(lower_case, "unset") == 0)
		dict->type_command = UNSET;
	else if (ft_strcmp(lower_case, "cd") == 0)
		dict->type_command = CD;
	else
		dict->type_command = UNDEFINED;
}

bool	ft_exit_status(t_dict *dict)
{
	while (dict->data[dict->i] && ft_isdigit(dict->data[dict->i]))
		--dict->i;
	if (!dict->data[dict->i] || (!ft_isdigit(dict->data[dict->i])
			&& !ft_isspace(dict->data[dict->i])))
	{
		ft_putstr("exit\n");
		return (true);
	}
	else
		while (dict->data[++dict->i] && ft_isspace(dict->data[dict->i]));
	return (false);
}

void	ft_putcommanderror(t_dict *dict)
{
	ft_putstr_fd("minishell: exit:", 2);
	ft_putstr_fd(dict->data, 2);
	ft_putstr_fd("numeric argument required\n", 2);
	g_signal.exit_status = COMMAND_NOT_FOUND;
}

int	ft_dict_init(t_dict *dict, int end_index, char *str)
{
	dictionary_t	*tmp;

	dict->i = find_data_int(str, dict->variable_dic);
	if (dict->i == -1)
	{
		tmp = ft_dictionary_create(str);
		if (tmp == NULL)
		{
			tmp = NULL;
			end_index++;
			return (end_index);
		}
		ft_dictionaryadd_back(&(dict->variable_dic), tmp);
	}
	else
		change_item(str, dict->i, dict->variable_dic);
	tmp = NULL;
	end_index++;
	return (end_index);
}
