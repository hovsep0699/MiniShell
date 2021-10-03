#include "minishell.h"

  int ft_external(t_last_command * dictioanry,char **envp, char **data, int count)
  {
    int fd[2];
    char *path;
    char *tmp_path;
    char **split_path;
    pid_t ret_fork;
    int i;
    int j;
    int ret_execv;
    char **av;
    int len;

    path = find_data("PATH",dictioanry->variable_dic);
    split_path = ft_strsplit(path,':');
    i = ft_vecstrlen(split_path);
    for (int ind = 0; ind < i; ++ind)
       split_path[ind] = ft_realloc_strjoin(split_path[ind], "/");  
    av = ft_vecstrinit(3);
    j = 0;
    if((ret_fork = fork()) == 0)
    {
       
       while (j < i)
       {
        tmp_path = ft_strdup(split_path[j]);
        tmp_path = ft_realloc_strjoin(tmp_path, data[dictioanry->last_command]);
        ft_strdel(&av[0]);
        ft_strdel(&av[1]);
        av[0] = ft_strdup(tmp_path);
        av[1] = ft_strdup(dictioanry->data);
        ret_execv = execve(tmp_path, av, envp);
        j++;
      }
      dictioanry->exit_status = COMMAND_NOT_FOUND;
      exit(0);
    }
    else
    {
      wait(NULL);
    }
    ft_vecstrdel(&split_path);
    ft_vecstrdel(&av);
    return dictioanry->exit_status;
  }
