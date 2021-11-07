BIN_DIR			=	bin

NAME			=	$(BIN_DIR)/minishell

SRCS_DIR		=	sources

OBJS_DIR		=	objects

SRCS			=	$(wildcard sources/*.c)

OBJS			=	$(patsubst sources/%.c, objects/%.o, $(SRCS))

CC				=	gcc

INCLUDES	 	=	-Iincludes -Ilibs/Libft/includes -Ilibs/Libft_Vache -I ~/.brew/opt/readline/include

RM				=	rm -f

RMDIR			=	rm -rf

MKDIR			=	mkdir -p

GCCFLAGS		=	#-Wall -Wextra -Werror

CFLAGS			=  $(GCCFLAGS) $(INCLUDES)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@if [ ! -d $(OBJS_DIR) ]; then $(MKDIR) $(OBJS_DIR); fi
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					@$(MAKELIBS)
					@$(MAKELIBS2)
					@if [ ! -d $(BIN_DIR) ]; then $(MKDIR) $(BIN_DIR); fi
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

clean:
					$(RMDIR) $(OBJS_DIR)
					$(MAKELIBFT) clean
					$(MAKELIBFT2) clean

fclean:				clean
					$(RMDIR) $(BIN_DIR)
					$(MAKELIBFT) fclean
					$(MAKELIBFT2) fclean

re:					
					$(RMDIR) $(OBJS_DIR)
					$(RMDIR) $(BIN_DIR)
					$(MAKE) all


.PHONY:				all clean fclean re libs







