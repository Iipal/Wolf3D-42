# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/03/16 22:22:38 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO = echo -e
	SDLFRAMEWORK = -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO = echo
	SDLINCLUDE = -F $(CURDIR)/frameworks
	SDLFRAMEWORK = -F $(CURDIR)/frameworks -rpath $(CURDIR)/frameworks -framework SDL2 \
		-framework SDL2_mixer -framework SDL2_ttf
endif

CC = gcc -march=native
CFLAGS = -Wall -Wextra -Werror -Ofast
INC = -I $(CURDIR)/includes/

SRC = srcs/main.c srcs/wolf_map_reader.c srcs/free/wolf_free.c srcs/init/wolf_init.c srcs/init/wolf_init_textures.c \
srcs/sdl/wolf_sdl_optimizing_load.c \
srcs/sdl/wolf_sdl_mainmenu_loop.c srcs/sdl/wolf_sdl_rendering_loop.c \
srcs/sdl/wolf_sdl_rendering_loop_key_press_events.c \
srcs/sdl/wolf_sdl_sfx_steps.c srcs/raycaster/wolf_raycaster.c srcs/raycaster/wolf_rotatenmove.c \
srcs/rendering/wolf_rendering.c srcs/rendering/wolf_main_menu.c \
srcs/rendering/wolf_colored.c srcs/rendering/wolf_textured.c \
srcs/rendering/wolf_textured_help_fck_norme.c srcs/rendering/wolf_minimap.c \
srcs/rendering/wolf_weapons.c srcs/rendering/wolf_torch.c srcs/rendering/wolf_fps_counter.c \
srcs/rendering/wolf_fog.c

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
	@$(CC) -c $(CFLAGS) $(SDLINCLUDE) $(INC) $< -o $@
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
