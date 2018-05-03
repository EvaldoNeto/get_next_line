#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eneto <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 19:05:57 by eneto             #+#    #+#              #
#    Updated: 2018/05/03 13:09:41 by eneto            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = get_next_line

FILES =		get_next_line.c	\
			main.c		

F_DIR = .
SRCS = $(addprefix $(F_DIR)/, $(FILES))

O_DIR = objs
OBJS = $(addprefix $(O_DIR)/, $(FILES:.c=.o))

HEADER = get_next_line.h
H_DIR = .
INC = $(addprefix $(H_DIR)/, $(HEADER))
INCLUDE = -I $(L_DIR) -I $(H_DIR)

L_DIR = libft
LIB = libft/libft.a
LIBLINK = -L ./$(L_DIR) -lft

all: libft $(NAME)

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBLINK)

$(O_DIR)/%.o:	$(F_DIR)/%.c $(INC)
		@mkdir -p $(O_DIR)
		@$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<
		@echo "Creation de "$@" OK"

libft:
		@make -C $(L_DIR)

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./libft clean

fclean:	clean
		rm -f $(NAME)
		$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re libft
