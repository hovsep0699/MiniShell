NAME = minishell
CC = gcc
INC = -I. -ILibs_Hoso/Libft/includes -IUtils
UTIL = ./Utils
SRCS = $(wildcard sources/*.c) minishell.c
OBJS = $(SRCS:.c=.o)

LINKERS = -LLibs_Hoso/Libft/bin -lft -LUtils -lft_vache -lreadline

%.o : %.c
			$(CC) $(CFLAGS) $(INC) -pthread -o $@ -c $<

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(MAKE) -C Libs_Hoso/Libft
			$(MAKE) -C ./Utils
			$(CC) $(FLAGS) $(INC) ./Utils/*.o  $(OBJS) -o $(NAME) $(LINKERS)

clean:
			$(MAKE) -C Libs_Hoso/Libft clean
			rm -rf $(OBJS)
			$(MAKE) clean -C ./Utils

fclean:		clean
			$(MAKE) -C Libs_Hoso/Libft fclean
			rm -f $(NAME)
			$(MAKE) fclean -C ./Utils
	
re:			fclean all

.PHONY:		all clean fclean re