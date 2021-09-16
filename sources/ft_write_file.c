#include "minishell.h"

int 			ft_write_file(struct	s_last_command * dictioanry,char **envp, char **data,int count)
{

    // int file2;
    int fd;
    int fd2;

   fd2 = dup(1);

    if((fd = open(dictioanry->name_file,O_WRONLY | O_TRUNC)) == -1)
    {
        ft_print_error(errno,strerror(errno),' ',dictioanry->name_file);
        return(SUCCESS);
    }
    if((dup2(fd,STDOUT_FILENO)) < 0)
        strerror(errno);
    dictioanry->function_pointer[dictioanry->type_command - 1][0](dictioanry,envp,data,count);
    close(fd);
    dup2(fd2,STDOUT_FILENO);
    ft_putstr_fd(dictioanry->data,1);
    return(1);
}

int only_create_file(char *file_name,struct	s_last_command *dictioanry)
{
    int fd;
    int len;

    len = ft_strlen(file_name);
    fd = open(file_name,O_CREAT,0777);
    close(fd);
    dictioanry->name_file = (char *)malloc(sizeof(char) * (ft_strlen(file_name) + 1));
    ft_strlcpy(dictioanry->name_file,file_name,len + 1);
    return(fd);
}