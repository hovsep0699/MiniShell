#include "minishell.h"

int exec_inout(char *line, char **envp, t_last_command *last_command)
{
	char **command;
	pid_t pid_child;
	char *tmp_line;
	int i;
	int count;
	int ret;

	tmp_line = enter_split_sapce(line);
	command = ft_split_Vache(tmp_line, ' ', CHAR_QUATES, CHAR_DQUATES);
	count = ft_vecstrlen(command);
	ft_default_set(last_command);
	if((ret = (system_command(command, last_command, envp, count))) >= 1)
		ft_putstr("Ok\n");
	else
		last_command->exit_status = ret;
	ft_strdel(&tmp_line);
	ft_vecstrdel(&command);
	ft_strdel(&last_command->name_file);
	return(1);
}
char *replace_str(char *curr_path)
{
	char *path;
	int j;
	int i;

	i = 0;
	j = 0;
	if((path = (char *)ft_calloc(ft_strlen(curr_path) + 1, sizeof(char))) == NULL)
		return(NULL);
	while (curr_path[i])
	{
		path[j] = curr_path[i];
		++i;
		++j;
	}
	return(path);
}
int quote_check(char *s, char exp, char exp2)
{
	int static exp_state;
	int static exp_state2;
	int i;
	int pipe_problem;

	exp_state = 1;
	exp_state2 = 1;
	pipe_problem = 0;
	i = 0;
	while (s[i])
	{
		if((s[i] == exp && exp_state2 == 1) && exp_state == 1)
			exp_state = 0;
		 else if ((s[i] == exp && exp_state2 == 1) && exp_state == 0)
			exp_state = 1;
		if((s[i] == exp2 && exp_state == 1) && exp_state2 == 1)
			exp_state2 = 0;
		else if((s[i] == exp2 && exp_state == 1) && exp_state2 == 0)
			exp_state2 = 1;
		if(exp_state2 && exp_state && s[i] == '|')
			pipe_problem++;
		i++;
	}
	if(!(exp_state && exp_state2))
		ft_putendl("quote ERROR");
	else if(ft_strlen(s) > 1 && s[i - 2] == '|')
		ft_putendl("Pipe Error");
	return((exp_state && exp_state2) && (ft_strlen(s) > 1 && s[i - 2] == '|'));
}
char		*ft_dis_strjoin2(char *s1, char *s2,int mod)
{
	char	*subjoin;
	size_t	i;
	int len_s1;
	int len_s2;

	len_s1 = ft_zero_byte_strlen(s1);
	len_s2 = ft_zero_byte_strlen(s2);
	i = 0;
	subjoin = (char *)ft_memalloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!subjoin)
		return (NULL);
	if (len_s1 > 0)
		i = ft_joins(s1, i,len_s1, subjoin);
	i = ft_joins(s2, i,len_s2, subjoin);
	return (subjoin);
}

void ft_setenv(char **envp, char *key, char *value)
{
	string_t str;
	string_t env_key;
	int key_index;

	env_key = ft_string_constructor(key);
	env_key.resize(&env_key, env_key.size + 1);
	env_key.data[env_key.size - 1] = '=';
	key_index = ft_vecstr_search2(envp, env_key.data, 0);
	str = ft_string_constructor(envp[key_index]);
	str.erase_between(&str, env_key.size + 1, str.size);
	str.join2(&str, value);
	// ft_strdel(&envp[key_index]);
	// envp[key_index] = ft_strdup(str.data);
	ft_strcpy(envp[key_index], str.data);
	ft_string_destructor(&str);
	ft_string_destructor(&env_key);
}

// void clear_env(char **envp)
// {
// 	int i = -1;
// 	while (envp[++i])
// 	{
// 		envp[i] = ft_strdup(NULL);
// 	}
// }




int main (int argv,char **args,char **envp)
{
	char *line;
	char *path;
	char *tmp;
	char **env;
	string_t root_path;
	char *curr_path;
	char *pwd;
	char *first;
	char *second;
	int count;
	
	t_last_command lcmd;
	int len;
	int i;
	count = 0;
	line = NULL;
	first = NULL;
	second = NULL;
	lcmd = ft_last_command_constructor();
	pwd = getenv("PWD");
	lcmd.variable_dic = ft_env_copy(envp);
	curr_path = pwd;
	while (true)
	{

		curr_path = ft_strrchr(curr_path, '/');
		if (!curr_path || count > PATH_SHOW_NUMBER + 1)
			break ;
		++count;
	}
	if (count > PATH_SHOW_NUMBER)
	{
		root_path = ft_string_constructor("..");
		curr_path = pwd;
		i = count - PATH_SHOW_NUMBER;
		while (i)
		{
			curr_path = ft_strchr(curr_path + 1, '/');
			--i;
		}
		root_path.join2(&root_path, curr_path);
	}
	else
		root_path = ft_string_constructor(pwd);
	path = replace_str(root_path.data);
	g_path = ft_string_constructor(TEXT_GREEN);
	g_path.join2(&g_path, path);
	g_path.join2(&g_path, "$> ");
	g_path.join2(&g_path, TEXT_WHITE);
	while (true)
	{
		ft_process_signal();
		ft_fd_open(&lcmd);
		line = readline(g_path.data);
		if (line)
			add_history(line);
		if(quote_check(line, CHAR_QUATES, CHAR_DQUATES))
		{
			ft_strdel(&line);
			continue;
		}
		exec_inout(line, envp, &lcmd);
		ft_strdel(&line);
	}
	ft_string_destructor(&g_path);
	ft_string_destructor(&root_path);
	ft_last_command_destructor(&lcmd);
	return 0;
}
