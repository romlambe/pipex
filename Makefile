# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 16:32:36 by romlambe          #+#    #+#              #
#    Updated: 2024/03/10 18:35:28 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRCS := src/main.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

all : author project $(NAME)

author:
		@echo "Author : romlambe\n"

project:
		@echo "Project : Pipex\n"

$(LIBFT):
		make -C libft

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		$(RM) $(OBJ)
		make clean -C libft

fclean:
		$(RM) $(NAME)
		make fclean -C libft

re:		author fclean all

.PHONY: all clean fclean re
