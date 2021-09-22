#include "minishell.h"

void ft_print_welcome(char *path)
{
	ft_putstr(TEXT_GREEN);
	ft_putstr(path);
	ft_putstr("$>");
	ft_putstr(TEXT_WHITE);
}

 int print_pipe(int pipe_count)
 {
	 while (pipe_count - 1)
	 {
		 ft_putstr("pipe ");
		 pipe_count--;
	 }
	 ft_putstr("pipe> ");
	 return(0);
 }

 void ft_print_error(int exeption,char *str_exeption,char element_exeption,char *command_name)
 {
	 switch (exeption)
	 {
	 case 	COMAND_NOT_FOUND:
			ft_putstr("\nzsh: command not found: ");
			ft_putstr(str_exeption);
		 break;
	case	PARSER_ERROR:
			ft_putstr_fd("zsh: parse error near `",1);
			ft_putchar_fd(element_exeption,1);
			ft_putchar_fd('\n',1);
		break;
	case WRONG_INPUT:
			ft_putstr_fd("Wrong Input\n",1);
	 break;
	 case BAD_ASSIGNMENT:
			ft_putstr_fd("zsh: bad assignment\n",1);
	 break;
	 case COMMAND_NOT_FOUND:
			ft_putstr_fd("zsh: ",1);
			ft_putstr_fd(str_exeption,1);
			ft_putstr_fd(" not found\n",1);
	 break;
	 case InvalidParameterName:
	 	ft_putstr_fd(command_name,1);
		ft_putchar_fd(element_exeption,1);
		ft_putstr_fd("invalid parameter name\n",1);
	  break;
	    case FIRSTDIGIT:
			ft_putstr("export: not an identifier: ");
			ft_putendl(str_exeption);
		break;
		case EACCES:
			ft_putstr("zsh: ");
			ft_putstr(str_exeption);
			ft_putchar(':');
			ft_putstr(command_name);
		break;
		case EISDIR:
		ft_putstr("sh: ");
		ft_putstr(str_exeption);
	 default: break;
	 }
 }