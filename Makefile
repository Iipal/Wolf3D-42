# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/03/03 22:12:01 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO = echo -e
	SDLFRAMEWORK = -lSDL2 -lSDL2_mixer -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO = echo
	SDLINCLUDE = -F ./frameworks
	SDLFRAMEWORK = -F./frameworks -rpath ./frameworks -framework SDL2
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -Ofast

SRC = srcs/main.c srcs/wolf_init.c srcs/wolf_map_reader.c \
srcs/wolf_sdl_optimizing_surface_load.c srcs/wolf_sdl_mainmenu_loop.c \
srcs/wolf_sdl_rendering_loop.c srcs/wolf_raycaster.c srcs/wolf_rendering.c \
srcs/wolf_rendering_mainmenu.c srcs/wolf_rendering_colored.c \
srcs/wolf_rendering_textured.c srcs/wolf_rendering_textured_help_fck_norme.c \
srcs/wolf_rotatenmove.c srcs/wolf_minimap.c srcs/wolf_fog.c srcs/wolf_free.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LMAKE = make -C libft

WHITE=\033[0m
BGREEN=\033[42m
GREEN=\033[32m
RED=\033[31m
INVERT=\033[7m

DEL = rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(SDLINCLUDE) $< -o $@
	@$(ECHO) "[$(GREEN)✓$(WHITE)]"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(ECHO) -n '\_______,-<=-=> ./$(NAME): '
	@$(CC) $(OBJ) $(SDLFRAMEWORK) $(LIBFT) -o $(NAME)
	@$(ECHO) "$(INVERT)[$(GREEN)✓$(WHITE)$(INVERT)]$(WHITE)"

del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(RED)deleted$(WHITE): ./$(NAME)"

re: fclean all

.PHONY: all fclean clean re
