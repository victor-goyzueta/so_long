# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:08:21 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/02/28 19:15:53 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = so_long
NAME_BNS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I library/libft
CFLAGS += -I library/minilibx-linux
CFLAGS += -I inc
CFLAGS += -I inc_bonus

LIBFT = library/libft/libft.a
MINILIBX = library/minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -L library/minilibx-linux -lmlx -lXext -lX11

SRCS =	src/main.c				\
		src/allocate_mem.c		\
		src/check_map_utils.c	\
		src/init_utils.c		\
		src/play_utils.c		\
		src/render_utils.c		\
		src/set_utils.c			\
		src/utils.c				\
		src/free_all_utils.c	\

SRCS_BNS =	src_bonus/main_bonus.c				\
			src_bonus/allocate_mem_bonus.c		\
			src_bonus/check_map_utils_bonus.c	\
			src_bonus/init_utils_bonus.c		\
			src_bonus/play_utils_bonus.c		\
			src_bonus/render_utils_bonus.c		\
			src_bonus/set_utils_bonus.c			\
			src_bonus/utils_bonus.c				\
			src_bonus/free_all_utils_bonus.c	\

OBJ = $(SRCS:src/%.c=objs/%.o)

OBJ_BNS = $(SRCS_BNS:src_bonus/%.c=objs_bns/%.o)
	
all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long ready$(WHITE)"

$(LIBFT):
	@make -C library/libft

$(MINILIBX):
	@make -C library/minilibx-linux --silent > /dev/null 2>&1

objs:
	@mkdir -p objs/src/

objs_bns:
	@mkdir -p objs_bns/src_bonus/

objs/%.o: src/%.c | objs
	@$(CC) $(CFLAGS) -c $< -o $@

objs_bns/%.o: src_bonus/%.c | objs_bns
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(MINILIBX) $(NAME_BNS)

$(NAME_BNS): $(OBJ_BNS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ_BNS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME_BNS)
	@echo "$(GREEN)so_long_bonus ready$(WHITE)"

clean:
	@make clean -C library/libft
	@make clean -C library/minilibx-linux
	@rm -rf objs
	@rm -rf objs_bns
	@echo "Objetcs files deleted."

fclean: clean
	@make fclean -C library/libft
	@make clean -C library/minilibx-linux
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re objs