#include "minishell.h"

int ft_qch(int state, int state2,char now_character, char quote)
{
    if((now_character == quote && state2 == 1) && state == 1)
	    return (0);
	else if ((now_character == quote && state2 == 1) && state == 0)
		return (1);
    return(state);
}

void set_default_gloabl()
{
	g_signal.pid = -1;
	g_signal.heredoc = 0;
}

int runfileutil(char **argum, t_dict *dict, int i)
{
	if (ft_strcmp(argum[i], ">>") == 0)
		dict->util_commant = DWRITE;
	else if (ft_strcmp(argum[i], "<<") == 0)
		dict->util_commant = DREAD;
	else if (argum[i][0] == '>')
		dict->util_commant = WRITE;
	else if (argum[i][0] == '<')
		dict->util_commant = READ;
	if(dict->util_commant != DREAD)
		i++;
	else
	{
		dict->name_file = ft_equal_strjoin(dict->name_file, dict, argum[i + 1], 1);
		i += 2;
	}
	return (i);
}

int	ft_isalnum_str(char *str, int *i)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isalnum(str[index]))
			break ;
		index++;
	}
	*i += index - 1;
	return (index);
}

int ft_execendline(char **arg, t_dict *dict, int count, char **envp_my)
{
	ft_search_side_func(dict)(dict, envp_my, arg, count);
	dict->index_command = dict->i + 1;
	ft_strdel(&dict->data);
	return (SUCCESS);
}