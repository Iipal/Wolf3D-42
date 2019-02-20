# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/02/20 11:27:47 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	SDLFRAMEWORK = -lSDL2 -lm
endif
ifeq ($(UNAME_S),Darwin)
	SDLINCLUDE = -I./frameworks/SDL2.framework/Headers/
	SDLFRAMEWORK = -F./frameworks -rpath ./frameworks -framework SDL2
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -Ofast

SRC = srcs/main.c srcs/wolf_init.c srcs/wolf_sdl_optimizing_surface_load.c \
srcs/wolf_map_reader.c srcs/wolf_sdl_loop.c srcs/wolf_raycaster.c \
srcs/wolf_rendering_colored.c srcs/wolf_rendering.c srcs/wolf_rendering_textured.c \
srcs/wolf_rendering_textured_help_fck_norme.c srcs/wolf_rotatenmove.c \
srcs/wolf_minimap.c srcs/wolf_fog.c srcs/wolf_free.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
GREEN=\033[32m
RED=\033[31m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n '$@: '
	@$(CC) -c $(CFLAGS) $(SDLINCLUDE) $< -o $@
	@echo "[$(GREEN)✓$(WHITE)]"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@echo -n '	<=-=> ./$(NAME):'
	@$(CC) $(OBJ) $(SDLFRAMEWORK) $(LIBFT) -o $(NAME)
	@echo "[$(GREEN)✓$(WHITE)]"

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
