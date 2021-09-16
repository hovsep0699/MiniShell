BIN_DIR			=	bin

NAME			=	$(BIN_DIR)/libft.a

MDEBUGGER		=	valgrind

DEBUGGER		=	gdb

MDBG_FLAGS		=	--leak-check=full -s

DEBUG_NAME		=	$(BIN_DIR)/debug

DEBUG_FLAGS		=	-g

DEBUG_DIR		=	debug

SRCS_DIR		=	sources

OBJS_DIR		=	objects

SRCS			=	$(wildcard sources/*.c)

OBJS			=	$(patsubst sources/%.c, objects/%.o, $(SRCS))

DEBUG_SRCS		=	$(wildcard debug/*.c)

DEBUG_OBJS		=	$(patsubst debug/%.c, debug/%.o, $(DEBUG_SRCS))

CC				=	gcc

AR				=	ar rcs

INCLUDES	 	=	includes

RM				=	rm -f

RMDIR			=	rm -rf

MKDIR			=	mkdir -p

CFLAGS			=	-Wall -Wextra -Werror -I$(INCLUDES)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@if [ ! -d $(OBJS_DIR) ]; then $(MKDIR) $(OBJS_DIR); fi
					$(CC) $(CFLAGS) -c $< -o $@

$(DEBUG_DIR)/%.o: $(DEBUG_DIR)/%.c
					$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS)
					@if [ ! -d $(BIN_DIR) ]; then $(MKDIR) $(BIN_DIR); fi
					$(AR) $(NAME) $(OBJS)

debug_clean:		
					$(RM) $(DEBUG_OBJS)

debug:				debug_clean $(DEBUG_OBJS)
					@if [ ! -d $(BIN_DIR) ]; then $(MKDIR) $(BIN_DIR); fi
					$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(DEBUG_NAME) $(DEBUG_OBJS) -Lbin -lft

memory:				debug
					$(MDEBUGGER) $(MDBG_FLAGS) $(DEBUG_NAME)

gdb:				debug
					$(DEBUGGER) $(DEBUG_NAME)

clean:
					$(RMDIR) $(OBJS_DIR)

fclean:				clean
					$(RMDIR) $(BIN_DIR)

re:					fclean all


.PHONY:				all clean fclean re 







