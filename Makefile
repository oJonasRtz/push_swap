# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2024/12/13 11:58:21 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_DIR = src
SRCS = swap.c ft_init.c validation.c push.c rotate.c reverse_rotate.c \
		already_sorted.c operations.c ft_solve.c operations2.c \
		ft_solve_utils.c events.c
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
	@echo "Compiling main"
	@$(CC) $(CFLAGS) $(SRC_DIR)/push_swap.c $(OBJ) $(LIBFT)/libft.a -o $(NAME)
	
clean:
	@echo "Objects removed."
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "$(NAME) removed." 
	@rm -f $(NAME)
	@rm -f $(PROGRAM)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re