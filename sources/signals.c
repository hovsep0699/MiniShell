#include "minishell.h"

void ft_signal_handle(int signum)
{
	if (signum == SIGINT || signum == SIGQUIT)
	{
		if(signum == SIGQUIT)
		{
			rl_replace_line("", 1);
			ft_putstr("Quit\n");
		}
		else
			ft_putchar('\n');
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int    ft_process_signal(void)
{
    signal(SIGINT, ft_signal_handle);
	signal(SIGQUIT, SIG_IGN);

    return(0);
}
