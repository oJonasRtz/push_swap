# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2025/01/03 14:23:33 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
SRCS = already_sorted.c events.c ft_init.c ft_solve_low.c ft_solve_low_utils.c \
	push.c reverse_rotate.c rotate.c move_both.c \
	swap.c validation_utils.c validation.c ft_solve_high.c ft_solve_high_utils.c \
	move_to_top.c best_push.c
	
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)
HEADER = include
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

#Creates libft.a. Copy to the current directory. Add libft.a to libprintf.a
$(NAME): $(OBJ) $(LIBFT)/libft.a
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) $(SRC_DIR)/main.c $(OBJ) $(LIBFT)/libft.a -o $(NAME)

clean:
	@echo "Objects removed."
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "$(NAME) removed."
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re