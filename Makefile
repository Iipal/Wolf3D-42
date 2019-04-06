# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/04/06 18:02:56 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d
PPATH := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
	LIBS := -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
	LIBSINC := -F $(CURDIR)/frameworks
	LIBS := -F $(CURDIR)/frameworks -rpath $(CURDIR)/frameworks -framework SDL2 \
		-framework SDL2_mixer -framework SDL2_ttf
endif

#	-march=native		- Setups compiler to use all available CPU instructions for
#							optimizing compiling time
#	-mtune=native		- Setups compiler to compiling all correctly for
#							current system architecture on which project compiling
#	-flto				- Enable Link Time Optimization
#	-Ofast				- MAXIMUM OPTIMIZATION
#	-fno-elide-type		- Do not elide types when printing diagnostics
CC := clang -march=native -mtune=native -flto -Ofast
CFLAGS := -Wall -Wextra -Werror -Wunused -fno-elide-type
IFLAGS := -I $(CURDIR)/includes/

SRC := $(abspath $(wildcard srcs/*.c))
SRC += $(abspath $(wildcard srcs/*/*.c))
OBJ := $(SRC:.c=.o)

LIBFT := libft/libft.a
LMAKE := make -C libft

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

DEL := rm -rf

all: $(NAME)

$(OBJ): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@$(ECHO) "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@$(ECHO) -n ' <q.p> | $(PPATH): '
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
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(PPATH)$(WHITE)"

re: fclean all

.PHONY: all fclean clean re
