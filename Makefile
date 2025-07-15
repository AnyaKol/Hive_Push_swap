# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 15:02:26 by akolupae          #+#    #+#              #
#    Updated: 2025/07/15 18:32:04 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

HDR = push_swap.h
HDR_B = checker_bonus.h

SRC = \
	push_swap_main.c \
	push_swap_utils.c \
	memo_utils.c \
	sort_stack.c \
	find_chain.c \
	fill_gaps.c \
	commands.c \

SRC_B = \
	checker_bonus.c \
	commands_bonus.c \

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(OBJ_DIR)/%.o)

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
LIB_HDR = $(LIB_DIR)/libft.h

COLOR = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIB_NAME)
	@echo "$(COLOR) Building $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBJ_DIR) $(OBJ_B) $(LIB_NAME)
	@echo "$(COLOR) Building $@$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(LIB_NAME)

$(LIB_NAME): $(LIB_HDR)
	@$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HDR) $(HDR_B)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@echo "$(COLOR) Cleaning $(NAME) and $(NAME_B)$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(COLOR) Removing $(LIB_NAME)$(RESET)"
	@rm -f $(LIB_NAME)
	@echo "$(COLOR) Removing $(NAME) and $(NAME_B)$(RESET)"
	@rm -f $(NAME) $(NAME_B)

re: fclean all

.SECONDARY: $(OBJ_DIR) $(OBJ) $(OBJ_B)
.PHONY: all clean fclean re bonus
