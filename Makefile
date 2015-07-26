# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	bsq
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES	=	main.c		\
			debug.c		\
			error.c		\
			intro.c		\
			libft.c		\
			libft2.c	\
			logic.c		\
			solve.c		\
			tell.c		\
			tool.c

INC		=	-I./includes
CCFLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

.PHONY: $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(INC) $(OBJS) -o $(NAME) -O3

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all
