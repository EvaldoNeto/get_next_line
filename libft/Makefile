#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eneto <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 14:56:05 by eneto             #+#    #+#              #
#    Updated: 2018/04/09 18:29:43 by eneto            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

LIB_NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS =		ft_atoi.c	\
		ft_bzero.c	\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memdel.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar.c	\
		ft_putchar_fd.c	\
		ft_putendl.c	\
		ft_putendl_fd.c	\
		ft_putnbr.c	\
		ft_putnbr_fd.c	\
		ft_putstr.c	\
		ft_putstr_fd.c	\
		ft_strcat.c	\
		ft_strchr.c	\
		ft_strclr.c	\
		ft_strcmp.c	\
		ft_strcpy.c	\
		ft_strdel.c	\
		ft_strdup.c	\
		ft_strequ.c	\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlen.c	\
		ft_strmap.c	\
		ft_strmapi.c	\
		ft_strncat.c	\
		ft_strncmp.c	\
		ft_strncpy.c	\
		ft_strnequ.c	\
		ft_strnew.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strsplit.c	\
		ft_strstr.c	\
		ft_strsub.c	\
		ft_strtrim.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_itoa.c		\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c	\
		btree_create_node.c	\
		btree_apply_postorder.c	\
		btree_node_level.c	\
		ft_max.c		\
		btree_height.c		\
		btree_print.c		\
		btree_print_level.c	\
		ft_power.c		\
		btree_nodes_per_level.c \
		btree_nodes_in_level.c	\
		btree_insert_data.c	\
		btree_right_rotate.c	\
		btree_left_rotate.c	\
		btree_insert_avl.c	\
		btree_search_data.c	\
		ft_strjoin_free.c	\
		btree_min.c		\
		btree_deletenode_avl.c	\
		get_next_line.c

OBJ = $(SRCS:.c=.o)

INC = ./

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $? $(SRCS)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBuilt library.\033[0m"	

main:
	@$(CC) $(FLAGS) $(LIB_NAME) -o $(NAME)

lib: $(OBJ)
	@ar ruv $(LIB_NAME) $(OBJ)
	@ranlib $(LIB_NAME)

%.o: $(SRCS)%.c
	@$(CC) -I $(INC) $(FLAGS) -c $< -o $@

so:
	@$(CC) $(FLAGS) -fPIC -c $(SRCS)
	@$(CC) -shared -o libft.so $(OBJ)	

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME) $(LIB_NAME) libft.so

re: fclean all
