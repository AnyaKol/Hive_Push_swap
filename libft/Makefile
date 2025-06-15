# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 15:29:34 by akolupae          #+#    #+#              #
#    Updated: 2025/06/02 13:31:26 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa_base.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_itoa_base.c \
	ft_max.c \
	ft_min.c \

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

PRINTF_DIR = ft_printf
PRINTF_HDR = $(PRINTF_DIR)/ft_printf.h

PRINTF_SRC = \
	$(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/ft_printf_flags.c \
	$(PRINTF_DIR)/ft_printf_format.c \
	$(PRINTF_DIR)/ft_printf_precision.c \
	$(PRINTF_DIR)/ft_printf_utils.c \
	
PRINTF_OBJ = $(PRINTF_SRC:$(PRINTF_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c $(PRINTF_HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ)
	ar -rcs $(NAME) $(OBJ)
	ar -rcs $(NAME) $(PRINTF_OBJ)

$(OBJ) $(PRINTF_OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ_DIR) $(OBJ) $(PRINTF_OBJ)
.PHONY: all clean fclean re
