#include "minishell.h"

int 			ft_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{

    int fd;

    if((fd = open(dictioanry->name_file,O_WRONLY | O_TRUNC)) == -1)
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

    if((fd = open(dictioanry->name_file,O_RDONLY)) == -1)
    {
        ft_print_error(errno, strerror(errno), ' ', dictioanry->name_file);
        return(SUCCESS);
    }
    if((dup2(fd, STDIN_FILE)) < 0)
        strerror(errno);
    ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
    close(fd);
    ft_fd_open(dictioanry);
    return(1);
}

int 			ft_double_write_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
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

int 			ft_dread_file(struct	s_last_command *dictioanry, char **envp, char **data, int count)
{
    int fd;

    /*while ()
    {
        
    }*/
    
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
    check_str = NULL;
    line = NULL;
    int p[2];

    check_str = ft_strdup(dictioanry->data);
    ft_strdel(&dictioanry->data);
    while (true)
    {
        // ft_putchar('\n');
         line = readline(">");
         add_history(line);
        if(ft_strcmp(check_str,line) == 0)
            break;
        if(dictioanry->data != NULL)
            ft_realloc_strjoin(dictioanry->data, "\n");
        ft_realloc_strjoin(dictioanry->data, line);
        //ft_strdel(&line);
    }
    ft_strdel(&check_str);
    ft_strdel(&line);
   // ft_putendl("chyort")
    if (pipe(p) < 0)
        exit(1);
   if ((fork()) > 0) {
        write(p[1], dictioanry->data, ft_zero_byte_strlen(dictioanry->data));
        wait(NULL);
   }
   else
   {
    // ft_search_builtin_func(dictioanry)(dictioanry, envp, data, count);
     exit(dictioanry->exit_status);
   }
    
return(1);
}