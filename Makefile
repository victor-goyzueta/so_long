# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:08:21 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/02/13 01:26:04 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I library/libft
CFLAGS += -I inc

LIBFT = library/libft/libft.a

SRCS = src/main.c\
	src/check_map.c\
	src/allocate_mem.c\

OBJ = $(SRCS:%.c=objs/%.o)
	
all: $(LIBFT) $(NAME)

$(NAME): objs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)so_long ready$(WHITE)"

$(LIBFT):
	@make -C library/libft

objs:
	@mkdir -p objs/src/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C library/libft
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make fclean -C library/libft
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re