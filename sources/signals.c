#include "minishell.h"

void handle(int signum)
{

    // printf("cntr c\n");
    if (!isatty(STDIN_FILE))
        exit(0);
	else
	{
		ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 0);
		/*rl_redisplay();*/
		rl_done = 1;
	}
	/*else*/
	/*{*/
		/*ft_putchar('\n');*/
		/*line = readline(g_path.data);*/
		/*add_history(line);*/
	/*}*/

}

int event(void)
{
	return 0;
}

int    ft_process_signal(void)
{
	rl_event_hook = event;
    signal(SIGINT, handle);
    return(0);
}
