# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 16:32:36 by romlambe          #+#    #+#              #
#    Updated: 2024/03/11 18:38:20 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRCS := src/pipex.c src/utils.c
SRCS_BONUS := src/pipex_bonus.c src/utils_bonus.c

LIBFT = libft/libft.a
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)
GNL_OBJ = $(GET_NEXT_LINE:.c=.o)

all : author project $(NAME)

bonus : author project $(NAME_BONUS)

author:
		@echo "Author : romlambe\n"

project:
		@echo "Project : Pipex\n"

$(LIBFT):
		make -C libft

$(NAME): $(OBJ) $(LIBFT) $(GNL_OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL_OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(GNL_OBJ)
		$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(GNL_OBJ) -o $(NAME_BONUS)

clean:
		$(RM) $(OBJ) $(OBJ_BONUS)
		$(RM) $(GNL_OBJ)
		make clean -C libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		make fclean -C libft

re:		author fclean all

.PHONY: all clean fclean re
