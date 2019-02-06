# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/02/06 22:10:31 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS := -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLXFLAGS := -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -g

SRC = srcs/main.c srcs/wolf_init.c srcs/wolf_map_reader.c srcs/wolf_key_hooks.c \
srcs/wolf_free.c srcs/wolf_rendering.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '+'
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "> $(NAME) $(GREEN)Compiled$(WHITE)"

del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(RED)deleted$(WHITE): ./$(NAME)"

re: fclean all

.PHONY: all fclean clean re
