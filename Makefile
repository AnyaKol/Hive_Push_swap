# **************************************************************************** #
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

NAME = libftprintf.a

HDR = ft_printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	ft_printf.c \
	ft_printf_flags.c \
	ft_printf_format.c \
	ft_printf_precision.c \
	ft_printf_utils.c \

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
LIB_HDR = $(LIB_DIR)/libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HDR) $(LIB_NAME)
	cp $(LIB_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIB_NAME): $(LIB_HDR)
	$(MAKE) -C $(LIB_DIR)

%.o: %.c $(LIB_HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
