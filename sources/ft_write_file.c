#include "minishell.h"

int 			ft_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{

    int fd;
    if(dictioanry->data == NULL)
    { 
        ft_putendl("syntax error\n");
        return(258);
    }
    if((fd = open(dictioanry->name_file, O_CREAT | O_WRONLY | O_TRUNC,0777)) == -1)
    {
        ft_print_error(errno, strerror(errno), ' ', "");
        ft_putstr("\n");
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
    if((fd = open(dictioanry->name_file, O_RDONLY)) == -1)
    {
        ft_putstr(strerror(errno));
        ft_putstr("\n");
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

    if((fd = open(dictioanry->name_file, O_CREAT |O_WRONLY | O_APPEND,0777)) == -1)
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
        ft_print_error(errno, strerror(errno), ' ', "");
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

    dictioanry->name_file = ft_equal_strjoin("", dictioanry, file_name, 1);
    fd = open("", O_CREAT, 0777);
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

    check_str = ft_strdup(dictioanry->data);
    ft_strdel(&dictioanry->data);
    dictioanry->data = NULL;
    pipe(p);
    g_signal.heredoc = 1;
    signal(SIGQUIT,&s_quit);
    int id = fork();
    g_signal.heredoc = 1;
    g_signal.pid = id;
    if(id == 0)
    {
        while (true)
        {
            line = readline(">");
            if(ft_strcmp(check_str, line) == 0)
                break;
            write(p[1], line, ft_zero_byte_strlen(line));
            write(p[1],"\n",1);
            ft_strdel(&line);
        }
        ft_strdel(&check_str);
        ft_strdel(&line);
        ft_pipe_close(p[1]);
        exit(1);
    }
   //dup2(p[0],STDOUT_FILENO);
    g_signal.heredoc = 0;
    //waitpid(id,)
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    ft_fd_open(dictioanry);
    return(1);
}