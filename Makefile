# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:08:21 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/02/19 19:30:49 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I library/libft
CFLAGS += -I library/minilibx-linux
CFLAGS += -I inc

LIBFT = library/libft/libft.a
MINILIBX = library/minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -L library/minilibx-linux -lmlx -lXext -lX11

SRCS = src/main.c\
	src/check_map.c\
	src/allocate_mem.c\
	src/init_utils.c\
	src/play_utils.c\
	src/utils.c\
	src/free_exit.c\

OBJ = $(SRCS:%.c=objs/%.o)
	
all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): objs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long ready$(WHITE)"

$(LIBFT):
	@make -C library/libft

$(MINILIBX):
	@make -C library/minilibx-linux --silent > /dev/null 2>&1

objs:
	@mkdir -p objs/src/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C library/libft
	@make clean -C library/minilibx-linux
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make fclean -C library/libft
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re