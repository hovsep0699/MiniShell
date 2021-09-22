#include "minishell.h"

int 			ft_write_file(struct	s_last_command * dictioanry,char **envp, char **data,int count)
{

    // int file2;
    int fd;
  //  int fd2;

  // fd2 = dup(1);

    if((fd = open(dictioanry->name_file,O_WRONLY | O_TRUNC)) == -1)
    {
        ft_print_error(errno,strerror(errno),' ',dictioanry->name_file);
        return(SUCCESS);
    }
    ft_putstr(dictioanry->data);
    
    if((dup2(fd,STDOUT_FILENO)) < 0)
        strerror(errno);
    dictioanry->function_pointer[dictioanry->type_command - 1][0](dictioanry,envp,data,count);
    close(fd);
   // dup2(fd2,STDOUT_FILENO);
  //  ft_putstr_fd(dictioanry->data,1);
    return(1);
}
int 			ft_Dwrite_file(struct	s_last_command * dictioanry,char **envp, char **data,int count)
{

    // int file2;
    int fd;
    int fd2;

   fd2 = dup(1);

    if((fd = open(dictioanry->name_file,O_WRONLY)) == -1)
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

    dictioanry->name_file = ft_equal_strjoin(dictioanry->name_file,dictioanry,file_name,0);
    fd = open(dictioanry->name_file,O_CREAT,0777);
    close(fd);
    return(fd);
}