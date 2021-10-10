#include "minishell.h"

int exec_inout(char *line, char **envp, t_last_command *last_command)
{
	char **command;
	pid_t pid_child;
	char *tmp_line;
	char *pipe_line;
	int i;
	int count;
	int ret;

	ft_default_set(last_command);
	pipe_line = ft_pipe(last_command, line);
	tmp_line = enter_split_sapce(&pipe_line);
	command = ft_split(tmp_line, ' ');
	count = ft_vecstrlen(command);
	ret = system_command(command, last_command, envp, count);
	last_command->exit_status = ret;
	ft_pipe_close(last_command->change_fd_in);
	ft_pipe_close(last_command->change_fd_out);
	ft_fd_open(last_command);
	if(last_command->isparrent == 0)
		exit(0);
	// printf("before pipe\n");
	ft_strdel(&tmp_line);
	ft_strdel(&pipe_line);
	ft_vecstrdel(&command);
	// printf("after pipe\n");
	return(1);
}
char *replace_str(char *curr_path)
{
	char *path;
	int j;
	int i;

	i = 0;
	j = 0;
	if((path = (char *)ft_calloc(ft_zero_byte_strlen(curr_path) + 1, sizeof(char))) == NULL)
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
	int flag_caharacter;

	exp_state = 1;
	exp_state2 = 1;
	pipe_problem = 1;
	flag_caharacter = 0;
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
	ft_strcpy(envp[key_index], str.data);
	ft_string_destructor(&str);
	ft_string_destructor(&env_key);
}

string_t ft_get_put_terminal()
{
	char pwd[PATH_MAX];
	char *curr_path;
	string_t root_path;
	string_t new_root_path;
	string_t new_new_path;
	int 	count;
	int len;
	int x;
	char *path;
	string_t g_path;

	count = -1;
	curr_path = getcwd(pwd, PATH_MAX);
	root_path = ft_string_constructor(pwd);
	x = root_path.size;
	len = root_path.size;

	while (++count < PATH_SHOW_NUMBER)
	{
		x = root_path.rfind4(&root_path, '/', x);
		if (x <= 0)
			break ;
	}
	root_path.erase_between(&root_path, 0, x);
	if (root_path.size != (size_t)len)
	{

		new_root_path = ft_string_constructor("..");
		new_new_path = ft_string_copy_constructor(&new_root_path);
		new_new_path.join(&new_new_path, &root_path);
	}
	else
	{
		new_root_path = ft_string_default_constructor();
		new_new_path = ft_string_copy_constructor(&root_path);
	}
	g_path = ft_string_default_constructor();
	g_path.join(&g_path, &new_new_path);
	g_path.join2(&g_path, "$> ");
	ft_string_destructor(&root_path);
	ft_string_destructor(&new_new_path);
	return(g_path);
}

int main (int argv,char **args,char **envp)
{
	char *path;
	char *tmp;
	char **env;
	char *curr_path;
	char *pwd;
	char *first;
	char *second;
	int count;
	string_t cwd_path;
	
	t_last_command lcmd;
	int len;
	int i;
	first = NULL;
	second = NULL;
	
	lcmd = ft_last_command_constructor();
	lcmd.variable_dic = ft_env_copy(envp);
	while (true)
	{
		cwd_path = ft_get_put_terminal();
		ft_fd_open(&lcmd);
		ft_process_signal(&lcmd);
		// signal(SIGINT, ft_signal_handle);
		// signal(SIGQUIT, SIG_IGN);
		if (!lcmd.line)
			lcmd.line = readline(cwd_path.data);
		add_history(lcmd.line);
		if (*lcmd.line)
		{
			if (quote_check(lcmd.line, CHAR_QUATES, CHAR_DQUATES))
			{
				ft_strdel(&lcmd.line);
				continue;
			}
			exec_inout(lcmd.line, envp, &lcmd);
		}

		ft_pipe_close(lcmd.change_fd_in);
		ft_pipe_close(lcmd.change_fd_out);
		ft_strdel(&lcmd.line);
		ft_string_destructor(&cwd_path);
	}
	ft_last_command_destructor(&lcmd);
	return 0;
}
