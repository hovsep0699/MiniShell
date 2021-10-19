#include "minishell.h"


// static bool g_is_parent;
/*void ft_signal_handle(int signum)
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
*/
void s_quit(int signum)
{
	(void)signum;
	//printf("\n%i\n",g_signal.pid);
	if (g_signal.pid > 0 && !g_signal.heredoc)
	{
		ft_putstr_fd("Quit (core dumped)\n", 1);
		g_signal.exit_status = 131;
	}
	else
		ft_putstr_fd(" \b\b", 2);
}

void s_int(int signum)
{
	(void)signum;
	if(g_signal.heredoc && g_signal.pid == 0)
	{
		ft_putstr_fd("\b\b\b^C\b\b", 1);
		exit(0);
	}
	if (g_signal.pid == 0)
		g_signal.exit_status = 1;
	else
	{
		ft_putstr_fd("\n", 2);
		rl_replace_line("", 0);
		if (g_signal.pid == -1)
			rl_on_new_line();
		rl_redisplay();
		g_signal.exit_status = 130;
	}

}
int    ft_process_signal(t_last_command *lcmd)
{

	// g_is_parent = lcmd->is_parent;
	// if (lcmd->is_parent)
	// {
		// ft_putstr("\nparent\n");
		//signal(SIGINT, ft_signal_handle);
		//signal(SIGQUIT, SIG_IGN);
	// }
	
	// signal(SIGQUIT, ft_signal_handle);
	// signal(SIGINT, ft_signal_handle);
		signal(SIGINT, &s_int);
		signal(SIGQUIT, &s_quit);
    return(0);
}
