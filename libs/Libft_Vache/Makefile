# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hohayrap <hohayrap@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 19:37:06 by vgaspary          #+#    #+#              #
#    Updated: 2021/09/23 17:29:15 by hohayrap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	$(wildcard *.c)

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -I. -I../Libft/includes

NAME			=	libft_vache.a

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus

