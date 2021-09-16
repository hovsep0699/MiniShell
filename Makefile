NAME = minishell
CC = gcc
INC = -I. -ILibs_Hoso/Libft/includes -IUtils
UTIL = ./Utils
SRCS = $(wildcard sources/*.c) minishell.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
			$(CC) $(CFLAGS) $(INC) -pthread -o $@ -c $<

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(MAKE) -C Libs_Hoso/Libft
			$(MAKE) -C ./Utils
			$(CC) $(FLAGS) $(INC) ./Utils/*.o  $(OBJS) -o $(NAME) -LLibs_Hoso/Libft/bin -lft -LUtils -lft_vache

clean:
			$(MAKE) -C Libs_Hoso/Libft clean
			rm -rf $(OBJS_DIR)
			$(MAKE) clean -C ./Utils

fclean:		clean
			$(MAKE) -C Libs_Hoso/Libft fclean
			rm -f $(NAME)
			rm -f $(NAME_BONUS)
			$(MAKE) fclean -C ./Utils
	
re:			fclean all

.PHONY:		all clean fclean re