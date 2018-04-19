#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eneto <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 19:05:57 by eneto             #+#    #+#              #
#    Updated: 2018/04/19 19:29:55 by eneto            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = get_next_line

LIB = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror 

SRCS = 	get_next_line.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

clean:
	@/bin/rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	$(MAKE) -C ./libft clean

re: fclean all
