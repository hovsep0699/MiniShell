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
	// ft_putstr(command[0]);
	if((ret = (system_command(command, last_command, envp, count))) >= 1)
		ft_putstr("Ok\n");
	else
		last_command->exit_status = ret;
	// ft_strdel(&last_command->data);
	//printf("\nha ha\n");
	ft_strdel(&tmp_line);
	ft_vecstrdel(&command);
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

int main (int argv,char **args,char **envp)
{
	char *line;
	char *path;
	char *tmp;
	char **env;
	string_t pwd;
	string_t oldpwd;
	int pwd_index;
	int oldpwd_index;
	int home_index;
	string_t str;
	t_last_command lcmd;
	int len;

	lcmd = ft_last_command_constructor();
	// lcmd.envp = ft_vecstrcpy(envp);
	// lcmd.pwd_index = ft_vecstr_search1(envp, "PWD");
	// lcmd.oldpwd_index = ft_vecstr_search1(envp, "OLDPWD");
	// lcmd.home_index	= ft_vecstr_search1(envp, "HOME");
	// pwd = ft_string_constructor("PWD=");
	// oldpwd = ft_string_constructor("OLDPWD=");
	// printf("%d %d %d %lu\n", lcmd.pwd_index, lcmd.oldpwd_index, lcmd.home_index, ft_zero_byte_strlen("HOME="));
	// pwd.join2(&pwd, envp[lcmd.home_index] + ft_zero_byte_strlen("HOME="));
	// oldpwd.join2(&oldpwd, envp[lcmd.home_index] + ft_zero_byte_strlen("HOME="));
	// ft_strdel(&lcmd.envp[lcmd.pwd_index]);
	// ft_strdel(&lcmd.envp[lcmd.oldpwd_index]);
	// lcmd.envp[lcmd.pwd_index] = ft_strdup(pwd.data);
	// lcmd.envp[lcmd.oldpwd_index] = ft_strdup(oldpwd.data);
	// printf("sranic chi\n");
	path = replace_str(getenv("PWD"));
	// printf("sranica\n");
	str = ft_string_default_constructor();
	str.join2(&str, path);
	str.join2(&str, "$> ");
	// str.join2(&str, TEXT_WHITE);
	// dir_now = opendir(path);
	// t_last_command * last_command;

	while (true)
	{
		ft_fd_open(&lcmd);
		line = readline(str.data);
		add_history(line);
		if(quote_check(line, CHAR_QUATES, CHAR_DQUATES))
		{
			ft_strdel(&line);
			continue;
		}
		exec_inout(line, envp, &lcmd);
		ft_strdel(&line);
	}
	ft_string_destructor(&str);
	ft_string_destructor(&pwd);
	ft_string_destructor(&oldpwd);
	ft_last_command_destructor(&lcmd);
	// ft_vecstrdel(&env);
	// ft_strdel(&root);
	return 0;
}