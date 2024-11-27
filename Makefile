# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 11:11:14 by jopereir          #+#    #+#              #
#    Updated: 2024/11/27 10:53:16 by jopereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftpushswap.a

SRC = swap.c ft_init.c push_swap_utils.c push.c rotate.c reverse_rotate.c
OBJ = $(SRC:.c=.o)
HEADER = include
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -g

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
	@rm -f my_program
	@make -C $(LIBFT) fclean

re: fclean all

main: re
	@echo "Compiling main.c"
	@$(CC) $(CFLAGS) main.c -L. -lftpushswap -o push_swap
	@$(MAKE) clean

.PHONY: all clean fclean re