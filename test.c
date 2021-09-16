#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/stat.h>
#include <errno.h>

int main (int argv,char **args,char **envp){
struct  stat st;
mode_t mode_file;
uid_t id_user;
char *env_my;
int fd;
int ret_val;
int errno_number;
//mode_file = st->st_mode;
  if(open("/Users/vgaspary/Downloads/minishell 2/d",O_WRONLY,0000) == -1)
  {
    errno_number = errno;
    printf("%s",strerror(errno_number));
  }
  ret_val = lstat("d",&st);
  //printf("%i",fd);
id_user =  getuid();
  //printf("\n%i",ret_val);
  //env_my = getenv(envp);
  //printf("\n%04o , %o,%o %s",st.st_mode,S_IFBLK,id_user,env_my);
}