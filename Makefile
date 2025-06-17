#
**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 15:29:34 by akolupae          #+#    #+#              #
#    Updated: 2025/06/02 13:29:52 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HDR = push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	push_swap.c \

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
LIB_HDR = $(LIB_DIR)/libft.h

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HDR) $(LIB_NAME)

$(LIB_NAME): $(LIB_HDR)
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(LIB_HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ) $(OBJ_DIR)
.PHONY: all clean fclean re
