# Main Exercise Name
NAME 			= 	minishell

# Main Directories Name
SRC_DIR 			= 	Src
HEREDOC_DIR_PATH	=	$(shell pwd)/.Heredoc
HEREDOC_DIR			=	\"$(HEREDOC_DIR_PATH)\"
OBJ_DIR				= 	Obj
INC_DIR				=	Include
FT_LIB				=	Libft
INC_DIR_LIB			= 	Include
INC_DIR_RL			= 	include
READ_DIR 			=	Readline
READ_UPDIR			=	Readline_update
READ_ARX 			=	lib
OS					=	$(shell uname -s)
PREFIX				=	$(shell pwd)/$(READ_UPDIR)

# Minishell Static Libraries File Name.
FT_ARX			=	libft.a

# Hierarchical Directories Path
EXEC_DIR		=	Executor
PARS_DIR		=	Parser
TOKS_DIR		=	Tokenizer
SHELL_DIR 		=	Shell
BILTIN_DIR 		=	Builtin
SEMATIC_DIR 	=	Sematic

# Hierarchical Directories Name
SRC_EXEC_DIR		=	$(SRC_DIR)/$(EXEC_DIR)
SRC_PARS_DIR		=	$(SRC_DIR)/$(PARS_DIR)
SRC_TOKS_DIR		=	$(SRC_DIR)/$(TOKS_DIR)
SRC_SHELL_DIR 		= 	$(SRC_DIR)/$(SHELL_DIR)
SRC_BILTIN_DIR 		= 	$(SRC_DIR)/$(BILTIN_DIR)
SRC_SEMATIC_DIR		=	$(SRC_DIR)/$(SEMATIC_DIR)
SRC_ALL_DIR			=	$(SRC_DIR) $(SRC_EXEC_DIR) $(SRC_PARS_DIR) $(SRC_TOKS_DIR) $(SRC_SHELL_DIR) $(SRC_BILTIN_DIR) $(SRC_SEMATIC_DIR)

OBJ_EXEC_DIR		=	$(OBJ_DIR)/$(EXEC_DIR)
OBJ_PARS_DIR		=	$(OBJ_DIR)/$(PARS_DIR)
OBJ_TOKS_DIR		=	$(OBJ_DIR)/$(TOKS_DIR)
OBJ_SHELL_DIR 		= 	$(OBJ_DIR)/$(SHELL_DIR)
OBJ_BILTIN_DIR		=	$(OBJ_DIR)/$(BILTIN_DIR)
OBJ_SEMATIC_DIR		=	$(OBJ_DIR)/$(SEMATIC_DIR)

OBJ_ALL_DIR			= 	$(OBJ_DIR) $(OBJ_EXEC_DIR) $(OBJ_PARS_DIR) $(OBJ_TOKS_DIR) $(OBJ_SHELL_DIR) $(OBJ_BILTIN_DIR) $(OBJ_SEMATIC_DIR)

INC_EXEC_DIR		=	$(INC_DIR)/$(EXEC_DIR)
INC_PARS_DIR		=	$(INC_DIR)/$(PARS_DIR)
INC_TOKS_DIR		=	$(INC_DIR)/$(TOKS_DIR)
INC_SHELL_DIR 		= 	$(INC_DIR)/$(SHELL_DIR)
INC_BILTIN_DIR 		= 	$(INC_DIR)/$(BILTIN_DIR)
INC_SEMATIC_DIR		=	$(INC_DIR)/$(SEMATIC_DIR)
INC_ALL_DIR 		= 	$(INC_DIR) $(INC_EXEC_DIR) $(INC_PARS_DIR) $(INC_TOKS_DIR) $(INC_SHELL_DIR) $(INC_BILTIN_DIR) $(INC_SEMATIC_DIR)


# # Single Flags
L_FLAG			=	-L
I_FLAG			=	-I
O_FLAG 			=	-o
C_FLAG 			=	-c
D_FLAG 			=	-D

# # File extension Variables
_C 				=	.c
_O 				=	.o
_H 				=	.h
_LIB 			=	.a

# Compiler and Linker Options Commands,
CC				=	cc
CD 				=	cd
RM				=	rm -rf
MK				=	mkdir -p
HARD_FLAG		=	-Wall -Wextra -Werror
DEFINES			=	$(D_FLAG)HEREDOC_DIR=$(HEREDOC_DIR)
SANIT_FLAG		=	-g3 -fsanitize=address
READ_FLAG		=	
CFLAGS			=	$(HARD_FLAG) $(SANIT_FLAG) $(DEFINES)

ifeq ($(OS),Darwin)
	READ_FLAG = $(READ_UPDIR)/$(READ_ARX)/libreadline$(_LIB) $(READ_UPDIR)/$(READ_ARX)/libhistory$(_LIB) -lncurses -ltermcap
else
	READ_FLAG = -lreadline -lhistory
endif

LINKERS			+=	 $(READ_FLAG) $(L_FLAG)$(FT_LIB) -lft

# Common Targets Variables
ALL 			=	all
CLEAN 			=	clean
FCLEAN 			=	fclean
RE 				=	re
RL 				=	Readline

# List of all Source Files
SRCS_EXEC		=	$(wildcard	$(SRC_EXEC_DIR)/*$(_C))
SRCS_PARS		=	$(wildcard	$(SRC_PARS_DIR)/*$(_C))
SRCS_TOKS		=	$(wildcard	$(SRC_TOKS_DIR)/*$(_C))
SRCS_SHELL		=	$(wildcard	$(SRC_SHELL_DIR)/*$(_C))
SRCS_BILTIN		=	$(wildcard	$(SRC_BILTIN_DIR)/*$(_C))
SRCS_SEMATIC	=	$(wildcard	$(SRC_SEMATIC_DIR)/*$(_C))

# List of all Object Files
OBJS_EXEC		=	$(patsubst 	$(SRC_EXEC_DIR)/%$(_C),$(OBJ_EXEC_DIR)/%$(_O),$(SRCS_EXEC))
OBJS_PARS		=	$(patsubst 	$(SRC_PARS_DIR)/%$(_C),$(OBJ_PARS_DIR)/%$(_O),$(SRCS_PARS))
OBJS_TOKS		=	$(patsubst 	$(SRC_TOKS_DIR)/%$(_C),$(OBJ_TOKS_DIR)/%$(_O),$(SRCS_TOKS))
OBJS_SHELL		=	$(patsubst 	$(SRC_SHELL_DIR)/%$(_C),$(OBJ_SHELL_DIR)/%$(_O),$(SRCS_SHELL))
OBJS_BILTIN		=	$(patsubst 	$(SRC_BILTIN_DIR)/%$(_C),$(OBJ_BILTIN_DIR)/%$(_O),$(SRCS_BILTIN))
OBJS_SEMATIC	=	$(patsubst 	$(SRC_SEMATIC_DIR)/%$(_C),$(OBJ_SEMATIC_DIR)/%$(_O),$(SRCS_SEMATIC))

# List of all Header Files
INCS_EXEC		=	$(wildcard 	$(INC_EXEC_DIR)/*$(_H))
INCS_PARS		=	$(wildcard 	$(INC_PARS_DIR)/*$(_H))
INCS_TOKS		=	$(wildcard 	$(INC_TOKS_DIR)/*$(_H))
INCS_SHELL 		= 	$(wildcard 	$(INC_SHELL_DIR)/*$(_H))
INCS_BILTIN 	= 	$(wildcard 	$(INC_BILTIN_DIR)/*$(_H))
INCS_SEMATIC 	= 	$(wildcard 	$(INC_SEMATIC_DIR)/*$(_H))

# Path lists of objects, headers, and source files.
SRCS_ALL 		=	$(SRCS_EXEC) $(SRCS_PARS) $(SRCS_TOKS) $(SRCS_SHELL) $(SRCS_BILTIN) $(SRCS_SEMATIC)
OBJS_ALL 		=	$(OBJS_EXEC) $(OBJS_PARS) $(OBJS_TOKS) $(OBJS_SHELL) $(OBJS_BILTIN) $(OBJS_SEMATIC)
INCS_ALL 		=	$(INCS_EXEC) $(INCS_PARS) $(INCS_TOKS) $(INCS_SHELL) $(INCS_BILTIN) $(INCS_SEMATIC)

# All include path
INCLUDES		=	$(I_FLAG)$(INC_DIR) $(I_FLAG)$(FT_LIB)/$(INC_DIR_LIB) $(I_FLAG)$(INC_EXEC_DIR) $(I_FLAG)$(INC_PARS_DIR) $(I_FLAG)$(INC_TOKS_DIR) $(I_FLAG)$(INC_BILTIN_DIR) $(I_FLAG)$(INC_SHELL_DIR) $(I_FLAG)$(INC_SEMATIC_DIR) $(I_FLAG)$(READ_UPDIR)/$(INC_DIR_RL) 
