#include "minishell.h"


static bool g_is_parent;
void ft_signal_handle(int signum)
{

	ft_putstr("\b");

	// if (signum == SIGINT || signum == SIGQUIT)
	// {
		
	// 	if(signum == SIGQUIT)
	// 	{
	// 		rl_replace_line("", 1);
	// 		ft_putstr("Quit\n");
	// 	}
	// 	else
	// 		ft_putchar('\n');
	// 	rl_on_new_line();
	// 	rl_replace_line("", 1);
		
		// rl_redisplay();
		// ft_putstr("Minishell$> ");
	// }
}



int    ft_process_signal(t_last_command *lcmd)
{

	g_is_parent = lcmd->is_parent;
	// if (!lcmd->is_parent)
	// {
	// 	printf("child\n");
	// 	signal(SIGQUIT, ft_signal_handle);
	// 	signal(SIGINT, SIG_IGN);
	// }
	// else
	// {
	// 	printf("parent\n");
	// 	signal(SIGINT, ft_signal_handle);
	// 	signal(SIGQUIT, SIG_IGN);
	// }
	
	signal(SIGQUIT, ft_signal_handle);
	signal(SIGINT, ft_signal_handle);
    return(0);
}
