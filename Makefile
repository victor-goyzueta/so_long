# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 18:08:21 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/03/04 18:37:33 by vgoyzuet         ###   ########.fr        #
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

INC = -I inc/

INC_BNS = -I bonus/inc/

LIBFT = library/libft/libft.a
MINILIBX = library/minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -L library/minilibx-linux -lmlx -lXext -lX11

MINILIBX_DIR = library/minilibx-linux
MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git

SRCS =	src/main.c				\
		src/allocate_mem.c		\
		src/check_map_utils.c	\
		src/init_utils.c		\
		src/play_utils.c		\
		src/render_utils.c		\
		src/set_utils.c			\
		src/utils.c				\
		src/free_all_utils.c	\

SRCS_BNS =	bonus/src/main_bonus.c				\
			bonus/src/allocate_mem_bonus.c		\
			bonus/src/check_map_utils_bonus.c	\
			bonus/src/init_utils_bonus.c		\
			bonus/src/play_utils_bonus.c		\
			bonus/src/render_utils_bonus.c		\
			bonus/src/set_utils_bonus.c			\
			bonus/src/utils_bonus.c				\
			bonus/src/free_all_utils_bonus.c	\

OBJ = $(SRCS:src/%.c=objs/%.o)
OBJ_BNS = $(SRCS_BNS:bonus/src/%.c=objs_bns/%.o)

	
all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long ready$(WHITE)"

bonus: clean $(LIBFT) $(MINILIBX) objs_bns $(OBJ_BNS)
	@$(CC) $(CFLAGS) $(INC_BNS) $(OBJ_BNS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long_bonus ready$(WHITE)"

$(LIBFT):
	@make -C library/libft
	
$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)/" ] || [ -z "$$(ls -A $(MINILIBX_DIR))" ]; then \
		echo "📥 Descargando MiniLibX..."; \
		rm -rf $(MINILIBX_DIR); \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	else \
		echo "✅ MiniLibX ya está presente"; \
	fi

$(MINILIBX): $(MINILIBX_DIR)
	@make -C $(MINILIBX_DIR) --silent > /dev/null 2>&1

objs:
	@mkdir -p objs/src/

objs_bns:
	@mkdir -p objs_bns/src/

objs/%.o: src/%.c | objs
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

objs_bns/%.o: bonus/src/%.c | objs_bns
	@$(CC) $(CFLAGS) $(INC_BNS) -c $< -o $@

clean:
	@make clean -C library/libft
	@make clean -C library/minilibx-linux
	@rm -rf objs objs_bns
	@echo "Objetcs files deleted."

fclean: clean
	@make fclean -C library/libft
	@make clean -C library/minilibx-linux
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all bonus clean fclean re objs objs_bns