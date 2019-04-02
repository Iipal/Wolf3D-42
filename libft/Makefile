# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 11:27:37 by tmaluh            #+#    #+#              #
#    Updated: 2019/04/02 19:44:38 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
PPATH := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
endif

CC := gcc -flto
LC := ar rcs
CFLAGS := -Wall -Wextra -Werror -Ofast

SRC_D := srcs/
SRCS := $(abspath $(wildcard $(SRC_D)/*/*.c))
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE := \033[0m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

all: $(NAME)

$(NAME): $(OBJS)
	@$(ECHO) "$(INVERT)"
	@$(ECHO) -n ' <=-=> | $(PPATH): '
	@$(LC) $(NAME) $(OBJS)
	@$(ECHO) "[$(GREEN)✓$(WHITE)$(INVERT)]$(WHITE)"
	@$(ECHO)

$(OBJS): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $< -o $@
	@$(ECHO) "$(SUCCESS)"
clean:
	@$(DEL) $(OBJS)

fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(PPATH)$(WHITE)"

re: fclean all

.PHONY: re fclean clean all
