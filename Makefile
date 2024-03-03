# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romlambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 16:32:36 by romlambe          #+#    #+#              #
#    Updated: 2024/03/03 17:00:43 by romlambe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

SRC = src/main.c

LIBFT = libft/libft.a
LIB = libft
INCLUDE = -I $(LIB)

OBJ = $(SRC.c=.o)


RM = rm -f

all:	$(NAME) $(LIBFT)
		@echo le projet pipex à été compilé avec succès

$(LIBFT):
		make -s -C $(LIB) all

%.o: %.c
	@$(CC) @$(CFLAGS) @$(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ) $(LIBFT)
			@$(CC) -o $(NAME) $(OBJS) -L ${LIB} -lft

clean:
		@$(RM) $(OBJS)
		@make -C $(LIB) clean > /dev/null

fclean:
		@$(RM) $(NAME)
		@make -C $(LIB) fclean > /dev/null

re:		fclean all
