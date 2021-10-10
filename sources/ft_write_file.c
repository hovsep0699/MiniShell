#include "minishell.h"

int 			ft_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{

    int fd;
    if(dictioanry->data == NULL)
    { 
        ft_putendl("syntax error\n");
        return(258);
    }
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
        printf("thisss\n");
        ft_putstr(strerror(errno));
        return(SUCCESS);
    }
    if((dup2(fd, STDIN_FILE)) < 0)
    {
        printf("this\n");
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

    check_str = ft_strdup(dictioanry->data);
    ft_strdel(&dictioanry->data);
    dictioanry->data = NULL;
    pipe(p);
    while (true)
    {
         line = readline(">");
        if(ft_strcmp(check_str, line) == 0)
            break;
         write(p[1], new_str, ft_zero_byte_strlen(new_str));
        if(dictioanry->data != NULL)
           new_str = ft_realloc_strjoin(new_str, "\n");
       new_str = ft_realloc_strjoin(new_str, line);
    }
   //dup2(p[0],STDOUT_FILENO);
    ft_pipe_close(p[1]);
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    ft_fd_open(dictioanry);
    return(1);
}