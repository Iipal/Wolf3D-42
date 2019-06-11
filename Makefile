# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/11 23:09:31 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d
NPWD := $(CURDIR)/$(NAME)

CC := gcc -march=native -mtune=native -flto -Ofast -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes/ -I $(CURDIR)/libft/includes
LIBSINC :=
LIBS :=

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LIBSINC += -I ~/.brew/include
	LIBS += -L ~/.brew/lib -rpath ~/.brew/lib
endif
LIBS += -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm

SRC := $(abspath $(wildcard srcs/*.c srcs/*/*.c))
OBJ := $(SRC:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := make -C libft

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS := [$(GREEN)✓$(WHITE)]
SUCCESS2 := [$(INVERT)$(GREEN)✓$(WHITE)]

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@echo "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(NAME): $(LIBFT) $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)
	@echo "$(SUCCESS2)"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@echo "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

$(CC_DEBUG):
	@$(eval CC=$(CC_DEBUG))
debug_all: $(CC_DEBUG) pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: $(CC_DEBUG) all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean

fclean: clean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: all fclean clean re pre debug debug_all set_cc_debug
