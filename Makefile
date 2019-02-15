# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/02/15 17:00:57 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS := -L /usr/local/lib -I /usr/local/lib -lmlx -lXext -lX11 -lm
	
	SDLFRAMEWORK = -lSDL2
endif
ifeq ($(UNAME_S),Darwin)
	MLXFLAGS := -L /usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit

	SDLINC = -I./frameworks/SDL2.framework/Headers/ -F./frameworks
	SDLFRAMEWORK = -F./frameworks -rpath ./frameworks -framework SDL2
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -g

SRC = srcs/main.c srcs/wolf_init.c srcs/wolf_map_reader.c srcs/wolf_key_hooks.c \
srcs/wolf_free.c srcs/wolf_rendering.c srcs/wolf_rotatenmove.c srcs/wolf_mouse_hooks.c \
srcs/wolf_raycaster.c srcs/wolf_rendering_textured.c srcs/wolf_rendering_colored.c \
srcs/wolf_minimap.c

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
	@$(CC) -c $(SDLINC) $(CFLAGS) $< -o $@

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(SDLFRAMEWORK) $(MLXFLAGS) $(LIBFT) -o $(NAME)
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
