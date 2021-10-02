#include "minishell.h"

void handle(int signum)
{
    char *line;

    line = NULL;
    // printf("cntr c\n");
    if (!isatty(STDIN_FILE))
        exit(0);
    else
    {   rl_on_new_line();
        rl_replace_line();
        rl_redisplay();
    }
   /* else
    {
        ft_putchar('\n');
        line = readline(g_path.data);
		add_history(line);
    }
    ft_strdel(&line);*/

}

int    ft_process_signal(void)
{

    signal(SIGINT, handle);
    return(0);
}