#include "minishell.h"

//  int ft_external(struct	s_last_command * dictioanry,char **envp, char **data, int count)
//  {
//      int fd[2];
//      int id;
//      int i;
//      int j;
//      int res;
//      char **exec_path;
//      char *execute_path;
//      char **argc;

//     i = 0;
//     argc = ft_split_Vache(dictioanry->data, ' ', CHAR_QUATES, CHAR_DQUATES);
//     while (count < i)
//     {
//         if(ft_strncmp(envp[i], "PATH", 4) == 0)
//             break;
//         i++;
//     }
//     i = 0;
//     exec_path = ft_split((*envp) + 5,':');
//     j = ft_vecstrlen(exec_path);
//     i = 0;
//     while (i < j)
//     {
//        execute_path = ft_realloc_strjoin(exec_path[i],"/");
//         execute_path = ft_realloc_strjoin(execute_path,dictioanry->data);
//        id = fork();
//        if(id == 0)
//        {
//           res = execv(execute_path,dictioanry->data);
//        }
//        else
            
//         i++;
//     }
//  }