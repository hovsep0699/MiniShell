#include "minishell.h"


int exec_inout(char *line, DIR *open_dir_now, char **envp, t_last_command *last_command)
{
	char **command;
	pid_t pid_child;
	char *tmp_line;
	int i;
	int count;
	
	i = 0;
	int ret;
	tmp_line = enter_split_sapce(line);
	command = ft_split_Vache(tmp_line, ' ', CHAR_QUATES, CHAR_DQUATES);
	count = ft_vecstrlen(command);
	ft_default_set(last_command);
	if((ret = (system_command(command, last_command, envp, count))) >= 1)
		ft_putstr("Ok\n");
	else
		last_command->exit_status = ret;
	ft_strdel(&last_command->data);
	//printf("\nha ha\n");
	ft_strdel(&tmp_line);
	ft_vecstrdel(&command);
	return(1);
}
char *replace_str(char *home_path)
{
	int i;
	char *path;
	int j;

	i = 0;
	j = 0;
	while(home_path[i] != '/')
	i++;
	if((path = (char *)malloc(sizeof(char) * ft_strlen(home_path)- 1)) == NULL)
		return(NULL);
	while (home_path[i])
	{
		path[j] = home_path[i];
		i++;
		j++;
	}
	return(path);
}
int quote_check(char *s,char exp,char exp2)
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
	DIR *dir_now;
	char *path;
	char *tmp;
	path = replace_str(envp[3]);

	string_t str;

	str = ft_string_constructor(TEXT_GREEN);
	str.join2(&str, path);
	str.join2(&str, "$> ");
	str.join2(&str, TEXT_WHITE);
	dir_now = opendir(path);
	int pipe_problem;
	t_last_command * last_command;
	int i;
	i = 0;
	last_command = (t_last_command *)malloc(sizeof(t_last_command));
	last_command->variable_dic = NULL;
	pipe_problem = 0;
    last_command->fd[0] = dup(STDIN_FILE);
    last_command->fd[1] = dup(STDOUT_FILE);
	while (true)
	{
		ft_fd_open(last_command);
		line = readline(str.data);
		add_history(line);
		if(quote_check(line, CHAR_QUATES, CHAR_DQUATES))
		{
			ft_strdel(&line);
			continue;
		}
		exec_inout(line, dir_now, envp, last_command);
		ft_strdel(&line);
	}
	ft_string_destructor(&str);
	// ft_strdel(&root);
	return 0;
}