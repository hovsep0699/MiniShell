#include "minishell.h"

int 			ft_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{

    int fd;
    char *name_file;
    if(dictioanry->data == NULL)
    { 
        ft_putendl("syntax error\n");
        return(258);
    }
    //name_file = ft_equal_strjoin(NULL, dictioanry, file_name, 1);
    if((fd = open(dictioanry->data, O_CREAT | O_WRONLY | O_TRUNC)) == -1)
    {
        ft_print_error(errno, strerror(errno), ' ', dictioanry->name_file);
        return(SUCCESS);
    }
    if((dup2(fd, STDOUT_FILENO)) < 0)
        strerror(errno);
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    close(fd);
    ft_fd_open(dictioanry);
    return(1);
}

int 			ft_read_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{

    int fd;
   
    if(dictioanry->data == NULL)
    { 
        ft_putendl("syntax error\n");
        return(258);
    }
    if((fd = open(dictioanry->data, O_RDONLY)) == -1)
    {
        ft_putstr(strerror(errno));
        return(SUCCESS);
    }
    if((dup2(fd, STDIN_FILE)) < 0)
    {
        strerror(errno);
    }
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    close(fd);
    ft_fd_open(dictioanry);
    return(1);
}

int 			ft_double_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{
    int fd;

    if((fd = open(dictioanry->data, O_CREAT |O_WRONLY | O_APPEND)) == -1)
    {
        ft_print_error(errno, strerror(errno), ' ', dictioanry->name_file);
        return(SUCCESS);
    }
    if((dup2(fd, STDOUT_FILENO)) < 0)
        strerror(errno);
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    close(fd);
    ft_fd_open(dictioanry);
    return(1);   
}

int 			ft_dread_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{
    int fd;

    if((fd = open(dictioanry->name_file, O_WRONLY | O_APPEND)) == -1)
    {
        ft_print_error(errno, strerror(errno), ' ', dictioanry->name_file);
        return(SUCCESS);
    }
    if((dup2(fd, STDOUT_FILENO)) < 0)
        strerror(errno);
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    close(fd);
    ft_fd_open(dictioanry);
    return(1);   
}
int only_create_file(char *file_name,struct	s_last_command *dictioanry)
{
    int fd;
    int len;

    dictioanry->name_file = ft_equal_strjoin(dictioanry->name_file, dictioanry, file_name, 1);
    fd = open(dictioanry->name_file, O_CREAT, 0777);
    close(fd);
    return(fd);
}

int ft_dwrite_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{
    char *line;
    char *check_str;
    char *new_str;
    check_str = NULL;
    new_str = NULL;
    line = NULL;
    int p[2];
    pid_t i;
    int break_loop;

    check_str = ft_strdup(dictioanry->data);
    ft_strdel(&dictioanry->data);
    dictioanry->data = NULL;
    pipe(p);
    //signal(SIGQUIT,&s_quit);
    int id = fork();
    signal(SIGQUIT,SIG_IGN);
    g_signal.heredoc = 1;
    g_signal.pid = id;
    if(id == 0)
    {
        ft_pipe_close(p[0]);
        while (true)
        {
            line = readline(">");
            if(ft_strcmp(check_str, line) == 0)
            {
                break;
            }
            write(p[1], line, ft_zero_byte_strlen(line));
            write(p[1],"\n",1);
            ft_strdel(&line);
        }
        ft_strdel(&check_str);
        ft_strdel(&line);
        ft_pipe_close(p[1]);
        //ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
        exit(1);
    }
    else
    {
        ft_pipe_close(p[1]);
        dup2(p[0],STDIN_FILENO);
        waitpid(id,NULL,0);
    }
   //dup2(p[0],STDOUT_FILENO);
    g_signal.heredoc = 0;
    //waitpid(id,)
    if(g_signal.exit_status != 130)
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    ft_fd_open(dictioanry);
    return(1);
}