# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 21:12:42 by gehovhan          #+#    #+#              #
#    Updated: 2023/12/25 20:01:21 by gevorg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main Exercise Name
NAME 			= 	libft
SRC_DIR 		= 	Src
OBJ_DIR			= 	Obj
INC_DIR			=	Include
FT_ARX			=	libft.a

OS 				=	$(shell uname -s)

# File extension Variables
_C 				=	.c
_O 				=	.o
_H 				=	.h

# Common Targets Variables
ALL 			=	all
CLEAN 			=	clean
FCLEAN 			=	fclean
RE 				=	re

# Single Flags
L_FLAG			=	-L
I_FLAG			=	-I
O_FLAG 			=	-o
C_FLAG 			=	-c

# CLI Variable
CC				=	cc
CD 				=	cd
RM				=	rm -rf
MK				=	mkdir -p

# Compiler and Linker Options
HARD_FLAG		=	-Wall -Wextra -Werror
SANIT_FLAG		=	-g3 #-fsanitize=address
CFLAGS			=	$(HARD_FLAG) $(SANIT_FLAG) -D$(OS)

# List of all Source Files
SRCS_EXEC		=	$(wildcard	$(SRC_DIR)/*$(_C))
INCS_EXEC		=	$(wildcard 	$(INC_DIR)/*$(_H))
OBJS_EXEC		=	$(patsubst 	$(SRC_DIR)/%$(_C),$(OBJ_DIR)/%$(_O),$(SRCS_EXEC))

INCLUDES		=	$(I_FLAG)$(INC_DIR) 


.DEFAULT_GOAL	:=	$(ALL)


define generate_rule_hier
$(info ✅ Generated object dir for $(2) module)
$(1): $(2)
	@$$(MK) $$@
endef

define generate_obj_rule_hier
$(info ✅ Generated objects for $(2) module)
$(1)/%$(_O): $(2)/%$(_C) $(3)
	$$(CC) $$(CFLAGS) $$(INCLUDES) $$(C_FLAG) $$< $$(O_FLAG) $$@ 
endef

$(eval $(call generate_rule_hier,$(OBJ_DIR),$(SRC_DIR)))
$(eval $(call generate_obj_rule_hier,$(OBJ_DIR),$(SRC_DIR),$(INCS_EXEC)))

$(ALL): $(FT_ARX)


$(FT_ARX):	$(OBJ_DIR) $(OBJS_EXEC)
	$(info ✅ Generate Objects For Libft)
	$(info ✅ Generate Archive For Libft)
	@ar rcs $(FT_ARX) $(OBJS_EXEC)

$(CLEAN):
	$(info ✅ Remove Objects From Libft)
	@$(RM) $(OBJ_DIR)

$(FCLEAN): 		$(CLEAN)
	$(info ✅ Remove archive from libft)
	@$(RM) $(FT_ARX)

$(RE):	$(FCLEAN) $(ALL)
	$(info ✅ Recompile Libft)


.PHONY: $(ALL) $(CLEAN) $(FCLEAN) $(RE) $(RL)

.SILENT: