# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luinasci <luinasci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 16:32:28 by luinasci          #+#    #+#              #
#    Updated: 2025/01/16 16:27:20 by luinasci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/ft_push_swap_main.c \
		src/ft_push_swap_pushers.c \
		src/ft_push_swap_radix_sorting.c \
		src/ft_push_swap_reverse_rotators.c \
		src/ft_push_swap_rotators.c \
		src/ft_push_swap_simple_sorting.c \
		src/ft_push_swap_swappers.c \
		utils/ft_push_swap_stack.c \
		utils/ft_push_swap_validators.c \
		utils/ft_push_swap_utils.c \
		utils/ft_push_swap_t_list.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap

HEADERS = include/ft_push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

re: fclean all
