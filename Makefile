# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/19 15:02:26 by akolupae          #+#    #+#              #
#    Updated: 2025/06/19 16:00:51 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HDR = push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	main.c \
	commands.c \
	utils.c \

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
LIB_HDR = $(LIB_DIR)/libft.h

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

COLOR = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HDR) $(LIB_NAME)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB_NAME)
	@echo "$(COLOR) Building $@$(RESET)"

$(LIB_NAME): $(LIB_HDR)
	@$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(LIB_HDR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)
	@echo "$(COLOR) Cleaning $(NAME)$(RESET)"

fclean: clean
	@rm -f $(LIB_NAME)
	@rm -f $(NAME)
	@echo "$(COLOR) Removing $(LIB_NAME)$(RESET)"
	@echo "$(COLOR) Removing $(NAME)$(RESET)"

re: fclean all

.SECONDARY: $(OBJ) $(OBJ_DIR)
.PHONY: all clean fclean re
