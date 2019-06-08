# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/08 13:55:59 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d
NPWD := $(CURDIR)/$(NAME)

ECHO := echo

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e

	PACKAGE_MANAGER := sudo dnf
	INSTALLED_LIBS_LIST := $(shell rpm -qa)
	SDL2_NECCESSARY_LIBS := SDL2-devel-2.0.9-3.fc30.x86_64 \
							SDL2_ttf-devel-2.0.15-2.fc30.x86_64 \
							SDL2_mixer-devel-2.0.4-3.fc30.x86_64
endif
ifeq ($(UNAME_S),Darwin)
	LIBSINC := --I ~/.brew/include
	LIBS := -L ~/.brew/lib -rpath ~/.brew/lib

	PACKAGE_MANAGER := brew
	INSTALLED_LIBS_LIST := $(shell $(PACKAGE_MANAGER) list)
	SDL2_NECCESSARY_LIBS := sdl2 sdl2_image sdl2_ttf
endif

LIBS := -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm

SDL2_INSTALLED_LIBS := $(filter $(SDL2_NECCESSARY_LIBS), $(INSTALLED_LIBS_LIST))
SDL2_NOT_INSTALLED_LIBS := $(filter-out $(SDL2_INSTALLED_LIBS),$(SDL2_NECCESSARY_LIBS))

CC := gcc -march=native -mtune=native -flto -Ofast
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes/

SRC := $(abspath $(wildcard srcs/*.c))
SRC += $(abspath $(wildcard srcs/*/*.c))
OBJ := $(SRC:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := make -C libft

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

DEL := rm -rf

all: $(SDL2_NOT_INSTALLED_LIBS) $(NAME)

$(SDL2_NOT_INSTALLED_LIBS):
ifneq ($(SDL2_NOT_INSTALLED_LIBS),)
	$(warning some SDL2 neccessary libs not founded, installing:)
	$(PACKAGE_MANAGER) install $(SDL2_NOT_INSTALLED_LIBS)
endif

$(OBJ): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@$(ECHO) "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(ECHO) -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)
	@$(ECHO) "[$(INVERT)$(GREEN)✓$(WHITE)]"

del:
	@$(DEL) $(OBJ)

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: all fclean clean re
