# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2024/12/02 10:00:23 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpushswap.a

SRC = swap.c ft_init.c push_swap_utils.c push.c rotate.c reverse_rotate.c \
		already_sorted.c operations.c ft_least_moves.c ft_solve.c operations2.c
OBJ = $(SRC:.c=.o)
HEADER = include
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g
PROGRAM = push_swap

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@
	
#Creates libft.a. Copy to the current directory. Add libft.a to libprintf.a
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME) 
	@echo "Creating $(NAME)."
	@ar rcs $(NAME) $(OBJ)

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

main: re
	@echo "Compiling main"
	@$(CC) $(CFLAGS) push_swap.c -L. -lftpushswap -o $(PROGRAM)
	@$(MAKE) clean

.PHONY: all clean fclean re